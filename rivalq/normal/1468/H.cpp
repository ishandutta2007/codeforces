#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
double pi = acos(-1);
#define tezi        ios_base::sync_with_stdio(false);\
                    cin.tie(0);\
                    cout.tie(0);
#define FOR(i,a,b)  for(int i=a;i<b;i++)
#define FORR(i,b,a) for(int i=b;i>=a;i--)
#define fill(a,b)   memset(a,b,sizeof(a))
#define _time_      1.0 * clock() / CLOCKS_PER_SEC
#define fi          first
#define se          second
#define mp          make_pair 
#define pb          push_back
#define all(a)      a.begin(),a.end()
#define rev(a)      reverse(all(a))
#define reva(a,n)   reverse(a,a+n)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll powerm(ll a,ll b,ll m){
    if(b==0) return 1;
    if(b&1) return a*powerm(a*a%m,b/2,m)%m;
    return powerm(a*a%m,b/2,m);
}
ll power(ll a,ll b){
    if(b==0) return 1;
    if(b&1) return a*power(a*a,b/2);
    return power(a*a,b/2);
}
ll sqroot(ll number){ 
    ll x = sqrt(number);
    while(x*x<number)x++;
    while(x*x>number)x--;
    return x;
}
ll cbroot(ll number){
    ll x = cbrt(number);
    while(x*x*x<number)x++;
    while(x*x*x>number)x--;
    return x;
}

const int maxn=2e5+5;
//bool prime[maxn];
ll b[maxn];

int main(){
    tezi
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //sieve
    //memset(prime,true,sizeof(prime)); 
    //for(ll p=2;p*p<maxn;p++)if(prime[p]==true)for(ll i=p*p;i<maxn;i+=p)prime[i]=false;
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> k >> m;
        int curr=0;
        for(int i=1;i<=m;i++){
            cin >> b[i];
        }
        if((n-m)%(k-1)){
            cout << "NO\n";
            continue;
        }
        if(n==m){
            cout << "YES\n";
            continue;
        }
        bool ok=0;
        for(int i=1;i<=m;i++){
            int a = b[i]-i;
            int c = n - m - a;
            if(a/(k-1)>0 && c/(k-1)>0){
                ok=1;
                break;
            }else{
                if(a==0 || c==0)
                    continue;
                if(a/(k-1)==0 && c/(k-1)>0){
                    a%=(k-1);
                    c%=(k-1);
                    if(a>=c){
                        ok=1;
                        break;
                    }
                }else if(a/(k-1)>0 && c/(k-1)==0){
                    a%=(k-1);
                    c%=(k-1);
                    if(c>=a){
                        ok=1;
                        break;
                    }
                }else{
                    if(a==c){
                        ok=1;
                        break;
                    }
                }
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}


/*
######                  ####### #     #   ###   #     #    #    ####### ####### ######
#     #  ######  #    # #     # ##   ##    #    ##    #   # #      #    #     # #     #
#     #  #       ##   # #     # # # # #    #    # #   #  #   #     #    #     # #     #
#     #  #####   # #  # #     # #  #  #    #    #  #  # #     #    #    #     # ######
#     #  #       #  # # #     # #     #    #    #   # # #######    #    #     # #   #
#     #  #       #   ## #     # #     #    #    #    ## #     #    #    #     # #    #
######   ######  #    # ####### #     #   ###   #     # #     #    #    ####### #     #
*/