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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int tot = n, power;
    for (power=2; power*2<=n; power*=2) {
        int cnt = n / power;
        for (int i=0; i<tot-cnt; i++)
            cout << power / 2 << " ";
        tot = cnt;
    }
    power /= 2;
    for (int i=power; i<=n; i+=power) {
        if (i + power <= n)
            cout << power << " ";
        else
            cout << i;
    }
    cout << "\n";

    return 0;
}