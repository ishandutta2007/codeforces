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
 
int n,t,ans[N];
pair<int,int> a[N],b[N];
 
void Main(){
	map<int,int> mark1,mark2;
	cin>>n;
	f(i,0,n){
		cin>>a[i].F;
		a[i].S=i;
	}
	f(i,0,n){
		cin>>b[i].F;
		b[i].S=i;
	}
	int mx=-1,res=0;
	sort(a,a+n);
	sort(b,b+n);
	f(i,0,n-1){
		mark1[a[i].S]=1;
		if(mark2[a[i].S]){
			res++;
		}
		mark2[b[i].S]=1;
		if(mark1[b[i].S]){
			res++;
		}
		if(i+1==res){
			mx=i;
		}
	}
	f(i,mx+1,n){
		ans[a[i].S]=1;
		ans[b[i].S]=1;
	}
	f(i,0,n){
		cout<<ans[i];
		ans[i]=0;
	}
	cout<<endl;
}
 
main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>t;
	while(t--){
		Main();
	}
}