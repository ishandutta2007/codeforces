#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3e5+30;

int n,h[N],w[N],st[N<<1][21],z[21];

inline int logg(int ww){
	int x = 0;
	while(z[x] <= ww) x++;
	return x-1;
}

inline int calc(int l,int r){
	int t = logg(r-l+1);
	if(h[st[l][t]] <= h[st[r-z[t]+1][t]]) return st[l][t];
	else return st[r-z[t]+1][t];
}

ll cal(int l,int r,int fl,int fr){
	if(l > r) return 0ll;
	int x = calc(l,r);
	if(!fl && !fr) return w[x]+cal(l,x-1,0,1)+cal(x+1,r,1,0);
	if(!fl) return max(0ll,cal(l,x-1,0,1)+max(0ll,w[x]+cal(x+1,r,1,1)));
	if(!fr) return max(0ll,cal(x+1,r,1,0)+max(0ll,w[x]+cal(l,x-1,1,1)));
	ll lv = cal(l,x-1,1,1) , rv = cal(x+1,r,1,1);
	return max(0ll,max(lv+rv+w[x],max(lv,rv)));
}

int main()
{
	z[0] = 1;
	for(int i=1;i <= 20;i++) z[i] = z[i-1]<<1;
	scanf("%d",&n);
	for(int i=1;i <= n;i++) scanf("%d",&h[i]); h[0] = 1e9;
	for(int i=1;i <= n;i++) st[i][0] = i;
	for(int j=1;j <= 19;j++)
		for(int i=1;i+z[j-1] <= n;i++)
			st[i][j] = h[st[i][j-1]] < h[st[i+z[j-1]][j-1]] ? st[i][j-1] : st[i+z[j-1]][j-1];
	for(int i=1;i <= n;i++) scanf("%d",&w[i]);
	printf("%lld\n",cal(1,n,0,0));
	return 0;
}