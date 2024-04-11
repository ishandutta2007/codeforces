#include<bits/stdc++.h>

#define LOCAL 0

#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const long double EPS = 1e-10;
const lli MOD = 1000000007ll;
const lli mod1 = 1000000009ll;
const lli mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;

using namespace std;

void print(int a[],int s,int e){for(int i=s;i<=e;i++)cout<<a[i]<<" ";cout<<"\n";}
void print(vector<int> &v,int s,int e){for(int i=s;i<=e;i++)cout<<v[i]<<" ";cout<<"\n";}
void print(vector<int> &v){for(int x:v)cout<<x<<" ";cout<<"\n";}

lli bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
lli bit(lli _mask,lli _i){return (_mask&(1<<_i))==0?0:1;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*b;x%=m;return x;}

int n;
int a[200010];
vector<int> G[200010];

void dfs(int u,int p=0){
    cout<<u<<" ";
    a[u] ^= 1;
    for(int v:G[u]){
        if(v!=p){
            dfs(v,u);
            if(a[v]){
                cout<<u<<" "<<v<<" "<<u<<" ";
            }
            else{
                a[u] ^= 1;
                cout<<u<<" ";
            }
        }
    }
}

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));

    si(n);
    for(int i=1;i<=n;i++)
        si(a[i]);

    for(int i=1;i<=n;i++){
        if(a[i] == 1)
            a[i] = 0;
        else
            a[i] = 1;
    }

    for(int i=1;i<=n-1;i++){
        int u,v;
        si(u);si(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    cout<<1<<" ";
    for(int i=0;i<G[1].size();i++){
        int v = G[1][i];
        dfs(v,1);
        a[1] ^= 1;
        cout<<1<<" ";
        if(i!=G[1].size()-1){
            if(a[v]){
                cout<<v<<" "<<1<<" ";
                a[1] ^= 1;
            }
        }
        else{
            if(a[1]){
                if(a[v]){
                    cout<<v<<" "<<1<<" ";
                }
                else{
                    cout<<v<<" "<<1<<" "<<v<<" ";
                }
            }
            else{
                if(a[v]){
                    cout<<v<<" ";
                }
            }
        }
    }

    return 0;
}