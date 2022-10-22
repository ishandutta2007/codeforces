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

const int N=1e5+2;

int t,n,a[N],u,v;

int main(){
    cin>>t;
    while(t--){
        int p=0,r=0;
        cin>>n>>u>>v;
        f(i,1,n+1){ cin>>a[i]; if(1<i && 1<abs(a[i]-a[i-1])) p=1; if(1<i && a[i]!=a[i-1]) r=1; }
        if(p==1) cout<<0<<endl;
        else{
            if(r) cout<<min(u,v)<<endl;
            else cout<<min(u,v)+v<<endl;
        }
    }
}