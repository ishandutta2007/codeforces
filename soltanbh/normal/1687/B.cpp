#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=1e6+99;

int n,m,res,ans,a[N];
string s;

int ask(){
	cout<<"? "<<s<<endl;
	cin>>res;
	return res;
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,0,m) s+='0';
	f(i,0,m){
		s[i]='1';
		a[i]=ask();
		s[i]='0';
	}
	vector<int> vec(m);
	iota(all(vec),0);
	sort(all(vec),[&](int u,int v){ return a[u]<a[v]; });
	int last=0;
	for(auto id : vec){
		s[id]='1';
		int now=ask();
		if(now-last==a[id]) ans+=a[id];
		last=now;
	}
	cout<<"! "<<ans<<endl;
}