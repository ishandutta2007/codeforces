#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

long long dmg[300000];
array<long long, 3> monster[300000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> monster[i][0] >> monster[i][1];
//            monster[i][2] = i;
        }

//        pair<long long, int> start(LLONG_MAX, -1);
        long long tot = 0;
        for (int i=0; i<n; i++) {
//            start = min(start, {monster[i]});
            dmg[i] = max(monster[i][0] - monster[(i-1+n)%n][1], 0LL);
            tot += dmg[i];
        }

        long long ret = LLONG_MAX;
        for (int i=0; i<n; i++) {
            ret = min(ret, tot - dmg[i] + monster[i][0]);
        }

        cout << ret << "\n";

//        memset(dmg, 0, sizeof(long long) * n);
//        sort(monster, monster + n, greater<array<long long, 3>>());
//
//        long long ret = 0;
//        for (int i=0; i<n; i++) {
//            ret += max(monster[i][1] - dmg[monster[i][2]], 0LL);
//            DEBUG(ret)
//            dmg[(monster[i][2]+1)%n] += monster[i][0];
//        }

//        cout << ret << "\n";
    }

    return 0;
}