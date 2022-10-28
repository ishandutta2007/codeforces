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

int n,x;
ld p[130];
ld mat[130][130],temp[130][130],res[130][130];
ld fin[130];

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));

    cout<<fixed<<setprecision(10);

    cin>>n>>x;
    for(int i=0;i<=x;i++)
        cin>>p[i];

    for(int j=0;j<=127;j++){
        for(int k=0;k<=127;k++){
            mat[j][k] += p[j^k];
        }
    }
    int b = n;
    int N = 127;
    for(int i=0;i<=127;i++)
        res[i][i] = 1.0;
    while(b){
        if(b%2==1){
            for(int i=0;i<=N;i++)
                for(int j=0;j<=N;j++)
                    temp[i][j] = 0;
            for(int i=0;i<=N;i++)
                for(int j=0;j<=N;j++)
                    for(int k=0;k<=N;k++)
                        temp[i][j] += res[i][k]*mat[k][j];
            for(int i=0;i<=N;i++)
                for(int j=0;j<=N;j++)
                    res[i][j] = temp[i][j];
        }
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                temp[i][j] = 0;
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                for(int k=0;k<=N;k++)
                    temp[i][j] += mat[i][k]*mat[k][j];
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                mat[i][j] = temp[i][j];
        b/=2;
    }
    ld ans = 0.0;
    for(int i=1;i<=127;i++)
        ans += res[i][0];

    cout<<ans;

    return 0;
}