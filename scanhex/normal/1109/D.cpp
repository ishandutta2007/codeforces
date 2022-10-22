#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int mod=1e9+7;
int mu(int a,int b){
	 return (nagai)a*b%mod;
}
void add(int&a,int b){
	 if((a+=b)>=mod)a-=mod;
}
int pw(int a,int b){
	 int c=1;
	 for(;b;a=mu(a,a),b>>=1)if(b&1)c=mu(c,a);
	 return c;
}

const int N=2000100;
int fact[N],rfact[N];
void init(){
	 fact[0]=1;
	 for(int i=0;i+1<N;++i)
		 fact[i+1]=mu(fact[i],i+1);
	 rfact[N-1]=pw(fact[N-1],mod-2);
	 for(int i=N-1;i>0;--i)
		 rfact[i-1]=mu(rfact[i],i);
}

int C(int n,int k){
	 return mu(fact[n],mu(rfact[k],rfact[n-k]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	init();
	int ans=0;
	for(int edgs=1;edgs<n&&edgs<=m;++edgs){
		int cnt1=C(m-1,edgs-1);
		int cur=cnt1;
		cur=mu(cur,fact[edgs-1]);
		cur=mu(cur,C(n-2,edgs-1));
		int rest=n-edgs-1;
		if(rest>0){
			cur=mu(cur,mu(edgs+1,pw(n,rest-1)));
		}
		cur=mu(cur,pw(m,n-(edgs+1)));
		add(ans,cur);
	}
	cout<<ans<<'\n';
	return 0;
}