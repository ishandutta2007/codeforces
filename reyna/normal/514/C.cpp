//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.1 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (700*1000)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e16+7;
ll tavan(ll a,ll b){return b?((tavan((a*a)%MOD,b>>1) * (b & 1?a:1)%MOD)%MOD):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] > a[y]; }
ifstream fin("subset.in");
ofstream fout("subset.out");
ll n,m,pw[N];
map <ll,bool> all;
int main()
{
	IB;
    cin>>n>>m;
    pw[0]=1;
    for(ll i=1;i<N;i++)
        pw[i]=(pw[i-1]*101)%MOD;    
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        ll now=s.size();

        for(int j=0;j<s.size();j++){
	        now+=(pw[j]*(s[j]))%MOD;
	        now=now%MOD;
        }
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='a')
                all[(now+pw[j])%MOD]=all[(now+2*pw[j])%MOD]=true;
            else if(s[j]=='b')
                all[(now-pw[j] + 100 *MOD)%MOD]=all[(now+pw[j])%MOD]=true; 
            else
                all[(now-pw[j] + 100 *MOD)%MOD]=all[(now-2*pw[j] + 100 *MOD)%MOD]=true;   
        }
            
    }
    for(ll i=0;i<m;i++)
    {
        string s;
        
        cin>>s;
        ll now=s.size();
        for(int j=0;j<s.size();j++){
	        now+=(pw[j]*(s[j]))%MOD;
	        now=now%MOD;
        }
        if(all[now])
            cout<<"YES\n";
        else
            cout<<"NO\n";   
    }
    return 0;
}