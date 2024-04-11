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

int n,t,a,b;

int main(){
	cin>>n;
	int l=1,r=n+1,mid;
	while(l+3<r){
	    mid=(l+r)/2;
	    cout<<"? "<<mid-1<<endl;
	    cin>>a;
	    cout<<"? "<<mid<<endl;
	    cin>>b;
	    if(a<b) r=mid;
	    else l=mid;
	}
	vector<pair<int,int> > v;
	f(i,l,r){
	    cout<<"? "<<i<<endl;
	    cin>>a;
	    v.pb(mp(a,i));
	}
	sort(v.begin(),v.end());
	cout<<"! "<<v[0].S<<endl;
}