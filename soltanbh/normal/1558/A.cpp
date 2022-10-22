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

int n,t,a[N],mark[N];

int main(){
	cin>>t;
	while(t--){
	    int a,b,ans=0,x,y;
	    cin>>a>>b;
	    x=(a+b)/2;
	    y=a+b-x;
	    f(i,0,min(x,a)+1){
	        if(a-i<=y){
	            //cout<<i+y-(a-i)<<endl;
	            mark[i+y-(a-i)]=1;
	            mark[a+b-(i+y-(a-i))]=1;
	        }
	    }
	    f(i,0,a+b+1) ans+=mark[i];
	    cout<<ans<<'\n';
	    f(i,0,a+b+1)
	        if(mark[i]){
	            cout<<i<<" ";
	            mark[i]=0;
	        }
	    cout<<'\n';
	}
}