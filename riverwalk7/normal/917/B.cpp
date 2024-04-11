#include<bits/stdc++.h>
using namespace std;
#define rep(i , a , b)	for(int i=a ; i<b ; i++)
#define repi(i , a) for(auto i = a.begin() ; i != a.end() ; i++)
#define io freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all(x) x.begin(), x.end()
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define eb emplace_back
#define dbg(x) cout << (#x) << " = " << x << endl;
#define fill(a , x) memset(a , x , sizeof(a))
#define si(n)	scanf("%lld",&n)
#define sc(n)   scanf("%c",&n)
#define sd(n)   scanf("%lf",&n)
#define pln(x) 	printf("%lld\n", x)
#define pr(x) 	printf("%lld ", x)
#define nl	printf("\n")
#define fout(a, b) cout << fixed << setprecision((b)) << (a)
#define ffs(a) __builtin_ffs(a)          // find first set
#define clz(a) __builtin_clz(a)          // count leading zeroes
#define ctz(a) __builtin_ctz(a)          // count trailing zeroes
#define popc(a) __ builtin_popcount(a)   // count set bits
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;                 //cout<<fixed<<setprecision(0)<<ans; print integral(+ve pr -ve) value of ans which is ldb
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
const int maxn=1<<21;                   //2097152(10^6)
const int N=int(1e5);
const ll mod=int(1e9)+7;      
const ll inf = 1e18;                 
const double PI = 3.1415926536;
inline int Set(int n,int pos)  { return n = n | 1<<pos;}
inline bool check(int n,int pos) { return n & 1<<pos;}
inline int Reset(int n, int pos) { return n=n & ~(1<<pos);}
inline int lastbit(int n) { return n & (-n);}
inline int gcd(int a, int b){return b ? gcd (b, a % b) : a;}
inline int lcm(int a,int b){return (a*b)/gcd(a,b);}
inline ll power(ll a,ll b){ll ans=1;a=a%mod;while(b){if(b&1) ans=(ans*a)%mod;b>>=1;a=(a*a)%mod;}return ans;}
inline ll invmod(ll a){ll ans=power(a,mod-2);return ans;}
inline ll Egcd(ll a, ll b, ll *x, ll *y){if(a==0){*x=0,*y=1;return b;}ll x1,y1;ll gcd=Egcd(b%a,a,&x1,&y1);*x=y1-(b/a)*x1;*y=x1;return gcd;}
inline int bs(int arr[],int l,int r,int item){if(l==r){if(arr[l]==item) return r;else return -1;}if(item<=arr[(l+r)/2]) return bs(arr,l,(l+r)/2,item);else return bs(arr,(l+r)/2+1,r,item);}
inline void fastin(int &x){x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}return;} 
int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int nleap[12]={31,28,31,30,31,30,31,31,30,31,30,31};
/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction
/////////////////////////////////////////////////////////////////////////////////
vector< pii > G[105];
int dp[105][105][27][2];
int n,m,v,u;
char ch;
int dfs(int i,int j,int ch,int turn){
    if(dp[i][j][ch][turn]!=-1) return dp[i][j][ch][turn];
    if(turn==0){
        bool win=0;
        for(auto child : G[i]) if(child.ss>=ch) {
            win|=dfs(child.ff,j,child.ss,turn^1);
            if(win==1) break;
        }
        return dp[i][j][ch][turn]=win;
    }else{
        bool win=1;
        for(auto child : G[j]) if(child.ss>=ch) {
            win&=dfs(i,child.ff,child.ss,turn^1);
            if(win==0) break;
        }
        return dp[i][j][ch][turn]=win;
    }
}
int main(){
	fio;
    cin>>n>>m;
    rep(i,0,m){
        cin>>v>>u>>ch;
        G[v].pb(mp(u,ch-'a'+1));
    }
    memset(dp,-1,sizeof dp);
    rep(M,1,n+1){
        rep(L,1,n+1){
            if(dfs(M,L,0,0)) cout<<"A";
            else cout<<"B";
        }
        cout<<endl;
    }
    return 0;
}