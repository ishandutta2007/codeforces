#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,ans=2e9,last[N],a[6],b[N];
set<pair<int,int> > s;

int main(){
    vector<pair<int,int> > v;
	f(i,0,6) cin>>a[i];
	cin>>n;
	f(i,0,n){
	    cin>>b[i];
	    f(j,0,6)
	        v.pb(mp(b[i]-a[j],i));
	}
	
	fill(last,last+N,2e9);
	f(i,0,n) s.insert(mp(2e9,i));
	sort(v.begin(),v.end());
	
	f_(i,v.size()-1,0){
	    int x=v[i].S;
	    s.erase(mp(last[x],x));
	    last[x]=v[i].F;
	    s.insert(mp(last[x],x));
	    minm(ans,int((*s.rbegin()).F-v[i].F));
	}
	cout<<ans;
}