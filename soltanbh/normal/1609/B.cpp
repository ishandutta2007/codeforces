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
#define int ll

const int N=1e6+99;

int n,q,ans,a[N];
string s;

int G(int x){
	if(x>n-3) return 0;
	return s[x]=='a' && s[x+1]=='b' && s[x+2]=='c';	
}

main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q>>s;
	f(i,0,n){
		ans+=G(i);
	}
	f(i,0,q){
		int x;
		char c;
		cin>>x>>c;
		x--;
		f_(j,x,max(0ll,x-2)){
			ans-=G(j);	
		}
		s[x]=c;
		f_(j,x,max(0ll,x-2)){
			ans+=G(j);	
		}
		cout<<ans<<endl;
	}
}