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

const int N=1e6+99,lg=31;

int n,k,a[N],d[4][4],r[4][4];

void ask(int u,int v){
    int x;
    cout<<"and "<<u<<" "<<v<<endl;
    cin>>d[u][v];
    d[v][u]=d[u][v];
    cout<<"or "<<u<<" "<<v<<endl;
    cin>>r[u][v];
    r[v][u]=r[u][v];
}
void solve(){
    ask(1,2);
    ask(2,3);
    ask(3,1);
    f(i,1,4){
        f(j,0,lg){
            vector<int> v;
            int mv=1;
            f(k,1,4){
                if(k!=i)
                    v.pb(k);
            }
            f(k,0,v.size()){
                int x=v[k];
                if((r[i][x]&(1<<j))==0) mv=0;
                if((d[i][v[0]]&(1<<j))==0 && (d[v[1]][v[0]]&(1<<j))>0) mv=0;
            }
            if(mv) a[i]+=(1<<j);
        }
    }
}

int main(){
    cin>>n>>k;
    solve();
    f(i,4,n+1){
        int u,v;
        cout<<"and "<<1<<" "<<i<<endl;
        cin>>u;
        cout<<"or "<<1<<" "<<i<<endl;
        cin>>v;
        f(j,0,lg){
            if((v&(1<<j))>0 && ((u&(1<<j))>0 || (a[1]&(1<<j))==0))
                a[i]+=(1<<j);
        }
    }
    sort(a+1,a+n+1);
    cout<<"finish "<<a[k];
}