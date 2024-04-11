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

int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i > 0) a[i] += a[i-1];
    }
    int s, f;
    cin >> s >> f;
    s--, f--;

    int mx = 0, day = -1;
    for (int i=0; i<n; i++) {
        int ans;
        if (f <= n)
            ans = a[f-1] - (s > 0 ? a[s-1] : 0);
        else
            ans = a[f-n-1] + a[n-1] - (s > 0 ? a[s-1] : 0);
        if (ans > mx)
            mx = ans, day = i + 1;

        s--, f--;
        if (s < 0)
            s += n, f += n;
    }

    cout << day << "\n";

    return 0;
}