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

int n,m,t,mark[N],res[N];

int main(){
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m;
        vector<vector<int> > v(m);
        f(i,0,m){
            int k;
            cin>>k;
            f(j,0,k){
                int x;
                cin>>x;
                if(j<2)
                    v[i].pb(x);
            }
            if(k==1) mark[v[i][0]]++;
            if((m+1)/2<mark[v[i][0]]) ans=0;
        }
        f(i,0,m){
            if(v[i].size()==1) res[i]=(v[i][0]);
            else{
                if(mark[v[i][0]]<(m+1)/2) res[i]=(v[i][0]),mark[v[i][0]]++;
                else res[i]=(v[i][1]),mark[v[i][1]]++;
                if((m+1)/2<mark[v[i][1]]) ans=0;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
            f(i,0,m) cout<<res[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
        f(i,0,m)
            f(j,0,v[i].size())
                mark[v[i][j]]=0;
    }
}