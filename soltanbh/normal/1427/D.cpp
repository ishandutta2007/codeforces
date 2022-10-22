#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
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

const int N=56;

int n,m,t,res,mark[N],mv[N];
vector<pair<int,int> > v;
vector<int> ans[N];

void print1(int x,int y,int z,int p,int n){
    vector<pair<int,int> > V;
    f(i,x+y+z,n) V.pb(v[i]);
    f(i,x+y,x+y+z) V.pb(v[i]);
    f(i,x,x+y) V.pb(v[i]);
    f(i,0,x) V.pb(v[i]);
    v=V;
}
void print2(int x,int y,int z,int p,int n){
    if(x) ans[n].pb(x);
    if(y) ans[n].pb(y);
    if(z) ans[n].pb(z);
    if(p) ans[n].pb(p);
    res++;
    //cout<<x<<" "<<y<<" "<<z<<" "<<p<<" "<<n<<endl;
}

void Sort(int n){
    //f(i,0,n) cout<<v[i].F<<" "<<v[i].S<<endl;
    int k=0,sum=0;
    if(n==1) return ;
    f(i,0,v.size()){
        mark[v[i].F]=i;
        mv[v[i].F]=sum;
        sum+=v[i].S;
        if(i<v.size()-1 && v[i].F+1==v[i+1].F){
            v[i].S+=v[i+1].S;
            v.erase(v.begin()+i+1);
            k=v[i].F;
            break;
        }
    }
    if(k==0){
        f(i,1,n)
            if(mark[i+1]<mark[i]){
                print2(mv[i+1],mv[i]-mv[i+1],v[mark[i]].S,m-mv[i]-v[mark[i]].S,n);
                print1(mark[i+1],mark[i]-mark[i+1],1,n-1-mark[i],n);
                break;
            }
        f(i,0,v.size()-1){
            mark[v[i].F]=i;
            if(v[i].F+1==v[i+1].F){
                v[i].S+=v[i+1].S;
                v.erase(v.begin()+i+1);
                k=v[i].F;
                break;
            }
        }
    }
    f(i,0,v.size()) if(k<v[i].F) v[i].F--;
   // cout<<endl;
    Sort(n-1);
}

int main(){
    cin>>n;
    m=n;
    f(i,0,n){
        int x;
        cin>>x;
        v.pb(mp(x,1));
    }
    Sort(n);
    cout<<res<<endl;
    f_(i,n,1)
        if(ans[i].size()){
            cout<<ans[i].size()<<" ";
            f(j,0,ans[i].size())
                cout<<ans[i][j]<<" ";
            cout<<endl;
        }
}