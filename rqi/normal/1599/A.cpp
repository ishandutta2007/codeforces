#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using fb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a , b) for(int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
    return b < a ? a = b, 1 : 0;
}

tcT> bool ckmax(T& a, const T& b){
    return a < b ? a = b, 1 : 0;
}

const int mx = 200005;
struct Eff{

int to_weight[mx];

char REV(char a){
    if(a == 'L') return 'R';
    return 'L';
}

void solve(){
    int N;
    cin >> N;
    vi A;
    for(int i = 1; i <= N; i++){
        int val; cin >> val;
        A.pb(val);
    }
    sor(A);
    for(int i = 0; i < N; i++){
        to_weight[i+1] = A[i];
    }

    string S;
    cin >> S;

    if(N % 2 == 0) S.pb('R');

    vector<pair<int, char>> placed_weights;

    pi rang = mp(0, 0);
    placed_weights.pb(mp(0, S[0]));
    for(int i = 2; i < sz(S); i+=2){ //i-1, i
        if(S[i] == S[i-2]){
            if(S[i] != S[i-1]){
                placed_weights.pb(mp(++rang.s, S[i-1]));
                placed_weights.pb(mp(++rang.s, S[i]));
            }
            else{
                rang.s+=2;
                placed_weights.pb(mp(rang.s, S[i]));
                placed_weights.pb(mp(rang.s-1, REV(S[i])));
            }
        }
        else if(S[i] != S[i-2]){
            if(S[i-1] == S[i]){
                rang.s++; rang.f--;
                placed_weights.pb(mp(rang.s, S[i]));
                placed_weights.pb(mp(rang.f, S[i]));
            }
            else{
                rang.s++; rang.f--;
                placed_weights.pb(mp(rang.f, S[i]));
                placed_weights.pb(mp(rang.s, S[i]));
            }
        }
    }
    
    if(N % 2 == 0) placed_weights.pop_back();

    int min_ele = MOD;

    map<int, int> m;

    for(auto u: placed_weights){
        ckmin(min_ele, u.f);
        m[u.f];
    }

    int cur_ele = 0;
    for(auto &u: m){
        u.s = ++cur_ele;
    }

    for(auto& u: placed_weights){
        u.f = m[u.f];
    }

    for(const auto& u: placed_weights){
        assert(u.f <= N);
        cout << to_weight[u.f] << " " << u.s << "\n";
    }

}

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    Eff e; e.solve();
}