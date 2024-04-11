#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
#define INFLL 1000000000000000000LL
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 55 //check limits you incompetent ree
vector<string> calcs;
vll basis;
bool sim(ll a){
    ll A = a;
    for(ll b : basis){
        A = min(A, A^b);
    }
    return A;
}
void add(ll a){
    ll A = a;
    for(ll b : basis){
        if((A^b) < A){
            calcs.pb(to_string(A) + " ^ " + to_string(b));
            //cout << A << " ^ " << b << "\n";
            A = A^b;
        }
    }
    if(A){
        int ind = 0;
        while(ind < basis.size() && basis[ind] > A) ++ind;
        basis.insert(basis.begin()+ind, A);
        //cout << "added " << A << "\n";
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rng(seed);

    ll x;
    cin >> x;
    add(x);
    while(true){
        ll a = rng()%basis.size();
        ll b = rng()%basis.size();
        if(basis[a] > INFLL || basis[b] > INFLL) continue;
        //cout << basis[a] << " + " << basis[b] << "\n";
        ll x = basis[a]+basis[b];
        if(sim(x)){
            calcs.pb(to_string(basis[a]) + " + " + to_string(basis[b]));
            add(x);
        }
        if(basis[basis.size()-1] == 1) break;
    }
    cout << calcs.size() << "\n";
    for(auto u : calcs) cout << u << "\n";

    return 0;
}