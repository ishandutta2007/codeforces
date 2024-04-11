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

int n,t,a[N][5];

bool cmp(int u,int v){
    int t=0;
    f(i,0,5)
        t+=(a[u][i]<=a[v][i]);
    return t>2;
}

int main(){
    f(i,0,5) a[0][i]=N;
    cin>>t;
    while(t--){
        int u=0;
        cin>>n;
        f(i,1,n+1){
            f(j,0,5)
                cin>>a[i][j];
            if(cmp(i,u)) u=i;
        }
        int ans=1;
        f(i,1,n+1)
            if(!cmp(u,i))
                ans=0;
        if(ans) cout<<u<<endl;
        else cout<<-1<<endl;
    }
}