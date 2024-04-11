#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005

#define F0R(i, a) for (ll i=0; i<(a); i++)
#define FOR(i, a, b) for(ll i=(a); i<(b); i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    ll sn = n, sm = m;

    if((n*m*2) % k != 0){
        cout << "NO\n";
        return 0;
    }

    //ll dblArea = n*m*2/k;
    ll toGet = k;

    bool twoNeeded = true;
    if(toGet % 2 == 0){
        twoNeeded = false;
        toGet /= 2;
    }


    ll prime = 2;
    while(toGet != 1){
        if(toGet % prime != 0){
            prime++;
            continue;
        }

        while(n % prime == 0 && toGet % prime == 0){
            n /= prime;
            toGet /= prime;
        }
        while(m % prime == 0 && toGet % prime == 0){
            m /= prime;
            toGet /= prime;
        }

        if(n % toGet == 0){
            n /= toGet;
            toGet = 1;
        }
        if(m % toGet == 0){
            m /= toGet;
            toGet = 1;
        }
    }

    if(twoNeeded){
        if(n*2<=sn)n*=2;
        else m*=2;
    }

    cout << "YES\n0 0\n" << n << " 0\n0 " << m << "\n";

    return 0;
}