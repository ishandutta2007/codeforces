#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N];

bool check(int x){
	vector<int> v;
	f(i,1,n+1) if(a[i]!=x) v.pb(a[i]);
	f(i,0,v.size()){
		if(v[i]!=v[v.size()-i-1])
			return 0;
	}
	return 1;
}
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n+1) cin>>a[i];
		int ans=1;
		f(i,1,n+1){
			if(a[i]!=a[n-i+1]){
				ans=0;
				if(check(a[i]) || check(a[n-i+1])){
					ans=1;
				}
				break;
			}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}