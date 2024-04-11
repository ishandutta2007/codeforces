#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

const int MX = 200025, x18 = 18, n18 = 1<<x18, n19 = n18<<1;

struct segtree{
	int dp[n19];
	
	void change(int x, int i){
		i += n18;
		dp[i] = x;
		while(i != 1){
			dp[i>>1] = max(dp[i],dp[i^1]);
			i >>= 1;
		}
	}
	
	int getmax(int i){
		i += n18;
		int res = dp[i];
		while(i){
			if((i&1) == 0) res = max(res,dp[i+1]);
			i >>= 1;
		}
		
		return res;
	}
};

segtree segx, segy;
int xtoy[MX], ytox[MX];
priority_queue<int,vector<int>,greater<int> > qx;
stack<int> st;

void plant(int p, int h){
	int x, mx;
	
	ytox[h] = p; xtoy[p] = h; qx.push(p);
	
	for(int j = h-10; j <= h; j++){
		if(ytox[j] != 0){
			x = ytox[j];
			st.push(j);
			segx.change(0,x);
		}
	}
	
	while(!st.empty()){
		h = st.top(); st.pop();
		x = ytox[h];
		mx = segx.getmax(x)+1;
		segx.change(mx,x);
		segy.change(mx,h);
	}
}


void cut(int l){
	int x, h, mx;
	
	while(l){
		x = qx.top(); qx.pop();
		if(xtoy[x] != 0){
			l--;
			h = xtoy[x];
			st.push(x);
			segy.change(0,h);
			segx.change(0,x);
		}
	}
	
	x = st.top(); st.pop();
	h = xtoy[x];
	xtoy[x] = ytox[h] = 0;
	
	while(!st.empty()){
		x = st.top(); st.pop();
		h = xtoy[x];
		mx = segy.getmax(h)+1;
		segx.change(mx,x);
		segy.change(mx,h);
		qx.push(x);
	}
}


int main(){
	int n, m, typ, p, h, x;
	
	scanf("%d%d",&n,&m);
	
	rep(i,m){
		scanf("%d",&typ);
		if(typ == 1){
			scanf("%d%d",&p,&h);
			plant(p,h-i+m+10);
		} else {
			scanf("%d",&x);
			cut(x);
		}
		
		printf("%d\n",segx.getmax(0));
	}
	
	return 0;
}