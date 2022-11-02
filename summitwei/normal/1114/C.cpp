#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000000000000LL
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
ll n, b;

ll sieve[MN];
void gs(){
    FOR(i, 2, MN-1){
        if(sieve[i] == 0){
            sieve[i] = i;
            for(ll j=i; j<MN; j+=i){
                sieve[j] = i;
            }
        }
    }
}

ll check(ll x){
    ll sum = 0;
    ll cn = n;
    while(cn >= x){
        sum += (cn/x);
        cn /= x;
    }
    //cout << n << " has " << sum << " facs of " << x << "\n";
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    gs();

    ll mn = INF;

    cin >> n >> b;
    ll ob = b;
    FOR(i, 2, 2+sqrt(ob)){
        //cout << "checking " << i << "\n";
        if(sieve[i] == i && b % i == 0){
            //mn = min(mn, check(i));
            //mn = min(mn, check(b/i));
            ll nt = 0;
            while(b % i == 0){
                b /= i;
                nt++;
            }

            //cout << nt << "facs of " << i << " detected\n";

            ll cur = check(i)/nt;
            mn = min(mn, cur);
        }
    }

    if(b != 1){
        //cout << "hmm\n";
        mn = min(mn, check(b));
    }

    cout << mn << "\n";
    
    return 0;
}