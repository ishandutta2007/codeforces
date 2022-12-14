#include <bits/stdc++.h>
#include <string.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define F first
#define S second
#define pb push_back
#define po pop_back()
#define R return
#define C continue
#define B break
#define mp make_pair
#define all(v) v.begin(),v.end()
#define endl '\n'
#define loop(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long >
#define vi vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define sll set<ll>
#define in insert
#define be begin()
#define si size()
#define oo 1e18
#define debug(x,s) cout << #x << " = " <<  x << s;
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int mod=1000000007 ;
const double PI = 3.14159265;
//vi prime;
//bool is_composite[100000009];
//void sieve (int n) {
//	fill (is_composite, is_composite + n, false);
//	for (int i = 2; i < n; ++i) {
//		if (!is_composite[i]) prime.push_back (i);
//		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
//			is_composite[i * prime[j]] = true;
//			if (i % prime[j] == 0) break;
//		}
//	}
//}
string add(string s1,string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    string ss = "";
    int i = 0,j = 0,nxt = 0;
    while(i<s1.size()||j<s2.size()||nxt){
        int temp = (i<s1.size()?s1[i]-'0':0)+(j<s2.size()?s2[j]-'0':0)+nxt;
        ss.push_back(temp%10+'0');
        nxt = temp/10;
        i++,j++;
    }
    reverse(ss.begin(),ss.end());
    return ss;
}
void yes(){cout << "YES" << '\n';}
void no(){cout << "NO" << '\n';}
//void factorial() {fact[0]=1;for(int i=1;i<1e6+10;i++) {fact[i]=(fact[i-1]*i);fact[i]%=mod;}}
bool cmp(const pair<int,string> &a,const pair<int,string> &b){return (a.F > b.F);}
ll ceil(ll x,ll y){return x%y ? x/y+1 : x/y;}
ll power(ll x,ll y,ll mo){ll r=1; x=x%mo; while(y){ if(y&1) r= (r*x%mo)%mo; y=y>>1; x=((x%mo)*(x%mo))%mo; } return r%mo; }
ll gcd(ll x , ll y){return y ? gcd(y,x%y):x;}
ll fac(ll x){return (x ? x*fac(x-1) : 1 );}
ll inv(ll x,ll y){return (x*power(y,mod-2,mod))%mod;}
//ll Twafiq1(int n, int r){ll res = fact[n];ll div=fact[n-r]*fact[r];div%=mod;div=power(div,mod-2,mod);return(res*div)%mod;}
ll Twafiq(int n, int r){ll res = fac(n);ll div=fac(n-r)*fac(r);div%=mod;div=power(div,mod-2,mod);return(res*div)%mod;}

/*************************************/
ll r , g , h , All , dp[2][1000000];
ll solve(int n,int h,int ALL){
    if(h==0)return ALL>=0;
    ll &ret=dp[n][h];
    if(ret+1) return ret;
    if(ALL-h<0)return 0;
    ret=0;
    if(n-h>=0) ret += solve(n-h,h-1,ALL-h);
    if(ALL-n-h>=0) ret += solve(n,h-1,ALL-h);
    return ret;
}
int main()
{
   // FastIO
#ifdef Fake_Plastic_Tree
    freopen("input.txt", "r+", stdin);
    cout << fixed << setprecision(6);
#endif // Fake_Plastic_Tree
    cin >> r >> g;
    All=r+g;
    while(h*(h+1)/2 <= All){
        h++;
    }
    h--;
    dp[0][0]=1;
    long long mod=1000000007;
    for(int i=1;i<=h;i++){
        for(int j=0;j<=r;j++){
            dp[i%2][j]=0;
            if(j-i>=0) dp[i%2][j]+=dp[(i+1)%2][j-i];
            if(All-(r-j)-i>=0) dp[i%2][j]+=dp[(i+1)%2][j];
            dp[i%2][j]%=mod;
        }
        All-=i;
    }
    long long ans=0;
    for (int i=0;i<=r;i++)
        ans+=dp[h%2][i],ans%=mod;
    cout<<ans<<endl;
    R 0;

}