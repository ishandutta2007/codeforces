#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
typedef long long INT;
typedef pair<INT,int> pii;
typedef vector<int> VI;

#define NN 10000100
int ch[NN][2];
int flag[NN], sum[NN];
int cur=1;

void add(int u, INT L, INT R, INT l, INT r, int fl){
	INT mid=L+R>>1;
	if(flag[u]&(1<<!fl)){
		puts("-1");
		exit(0);
	}
	if(l<=L && R<=r){
		if(sum[u]&(1<<!fl)){
			puts("-1");
			exit(0);
		}
		flag[u]=sum[u]=1<<fl;
		return ;
	}
	if(l<mid){
		if(!ch[u][0]) ch[u][0]=++cur;
		add(ch[u][0], L, mid, l, r, fl);
	}
	else {
		if(!ch[u][1]) ch[u][1]=++cur;
		add(ch[u][1], mid, R, l, r, fl);
	}
	sum[u]=flag[u]|sum[ch[u][0]]|sum[ch[u][1]];
}

vector <pii> ans;

void solve(int u, INT L, INT R){
	if(sum[u]<=1) return ;
	if(sum[u]==2){
		ans.pb(pii(L, __builtin_ctzll(R-L)));
		return ;
	}
	if(ch[u][0]) solve(ch[u][0], L, L+R>>1);
	if(ch[u][1]) solve(ch[u][1], L+R>>1, R);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	
	int n;
	cin >> n;
	
	char s[111];
	
	INT mx=1LL<<32;
	
	while(n--){
		scanf("%s", s);
		int flag=s[0]=='-';
		char *t=strtok(s+1, "./");
		int a[5], cnt=0;
		while(t){
			a[cnt++]=atoi(t);
			t=strtok(NULL, "./");
		}
		
		INT x=0;
		for(int i=0; i<4; i++) x=x<<8|a[i];
		
		if(cnt==4) add(1, 0, mx, x, x+1, flag);
		else add(1, 0, mx, x, x+(1LL<<32-a[4]), flag);
	}
	
	solve(1, 0, mx);
	
	cout << ans.size() << endl;
	for(pii p : ans){
		int a[4];
		INT x=p.x;
		for(int i=4; i--; ) a[i]=x&255, x>>=8;
		printf("%d.%d.%d.%d/%d\n", a[0], a[1], a[2], a[3], 32-p.y);
	}
	
	return 0;
}