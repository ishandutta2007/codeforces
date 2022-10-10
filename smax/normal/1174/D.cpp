#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

bool taken[1<<18] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, x;
    cin >> n >> x;

    vector<int> ret;
    taken[x] = true;
    for (int i=1; i<1<<n; i++)
        if (!taken[i]) {
            ret.push_back(i);
            taken[i] = taken[i ^ x] = true;
        }

    cout << ret.size() << "\n";
    for (int i=0; i<ret.size(); i++)
        cout << (ret[i] ^ (i > 0 ? ret[i-1] : 0)) << " ";
    cout << "\n";

    return 0;
}