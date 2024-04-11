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
        f(i,0,N) mark[i]=0;
        cin>>n;
        f(i,0,n){
            cin>>a[i];
            if(a[i]<0) a[i]=-a[i];
        }
        int res=0;
        f(mask,0,(1<<n)){
            int sum=0;
            f(i,0,n)
                if(mask&(1<<i))
                    sum+=a[i];
            mark[sum]++;
            if(mark[sum]>1) res=1;
        }
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}