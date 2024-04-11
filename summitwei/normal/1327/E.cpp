#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
ll modExp(ll b, ll ex){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % MOD;
            ex /= 2;
        } else{
            prod = (prod*b) % MOD;
            ex--;
        }
    }
    
    return prod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        if(i == n){
            cout << "10 ";
        } else if(i == n-1){
            cout << "180 ";
        } else{
            ll res1 = modExp(10, n-i-2)*810*(n-i-1);
            res1 %= MOD;
            ll res2 = modExp(10, n-i-1)*180;
            res2 %= MOD;
            cout << (res1+res2)%MOD << " ";
        }
    }

    return 0;
}