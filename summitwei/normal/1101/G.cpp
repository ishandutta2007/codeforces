#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
ll val[MN];
vll a;

vll makeBasis(vll x){
    vll basis;
    for(ll a : x){
        ll A = a;
        for(ll b : basis) A = min(A, A^b);
        if(A){
            int ind = 0;
            while(ind < basis.size() && basis[ind] > A) ++ind;
            basis.insert(basis.begin()+ind, A);
        }
    }
    return basis;
}
//maximize number of elements st still w/o null space
//bs on answer? if smthn is possible can merge two adj
//do smthn so that answer is basis?????
//if xor of all values is 0 then -1
//wait wtf is it just this

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ll cxor = 0;
    FOR(i, 1, n){
        cin >> val[i];
        cxor ^= val[i];
        a.pb(cxor);
    }
    if(cxor == 0){
        cout << "-1\n";
        return 0;
    }
    cout << makeBasis(a).size() << "\n";

    return 0;
}