#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

template<class K> struct sp64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const K& x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash<K>()(x) + FIXED_RANDOM);
    }
};
template<class K, class V> using umap = gp_hash_table<K, V, sp64_hash<K>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int A, B;
    cin >> A >> B;

    vi notes;
    int sum = 0;
    for (int v = 1; ; v++) {
        if (sum + v > A + B) {
            break;
        }
        sum += v;
        notes.push_back(v);
    }
    reverse(all(notes));

    vi p, q;
    int ps = 0;
    for (int i = 0; i < notes.size(); i++) {
        if (ps + notes[i] > A) {
            if (A - ps > 0)
                p.push_back(A - ps);
            for (int j = i; j < notes.size(); j++) {
                if (notes[j] != A - ps) {
                    q.push_back(notes[j]);
                }
            }
            break;
        } else {
            p.push_back(notes[i]);
            ps += notes[i];
        }
    }

    cout << p.size() << "\n";
    for (int v : p) cout << v << " ";
    cout << endl;
    cout << q.size() << "\n";
    for (int v : q) cout << v << " ";
    cout << "\n";

    return 0;
}