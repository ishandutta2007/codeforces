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

const int N=105;

int n,m,t,b[N][N],ans[N][N],marK[N];
map<int,int> mark;

int main(){
    cin>>t;
    while(t--){
        mark.clear();
        int c=0;
        vector<int> v;
        cin>>n>>m;
        f(i,0,n)
            f(j,0,m)
            ans[i][j]=0;
        f(i,0,n)
            f(j,0,m){
                int u;
                cin>>u;
                b[i][j]=u;
                v.pb(u);
            }
        sort(v.begin(),v.end());
        f(i,0,m) mark[v[i]]++;
        f(i,0,n){
            set<int> s;
            f(i,0,m) s.insert(i);
            fill(marK,marK+N,0);
            f(j,0,m)
                if(mark[b[i][j]]){
                    marK[j]=1;
                    mark[b[i][j]]--;
                    s.erase(c);
                    ans[i][c++]=b[i][j];
                }
            f(j,0,m)
                if(marK[j]==0){
                    int u=*s.begin();
                    s.erase(u);
                    ans[i][u]=b[i][j];
                }
        }
        f(i,0,n){
            f(j,0,m)
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
    }
}