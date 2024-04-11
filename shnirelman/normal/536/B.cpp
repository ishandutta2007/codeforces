#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;

const int N = 20 + 1;
const int A = 26;

/*

*/

struct Hash_str {
    string s;
    int n;

    int p = 43;
    int M = 1e9 + 9;
    vector<int> pw, h;

    Hash_str(string s1) : s(s1) {
        n = s.length();

        pw.resize(n + 1, 1);
        h.resize(n + 1, 0);

        for(int i = 1; i < pw.size(); i++) {
            pw[i] = pw[i - 1] * 1ll * p % M;
        }

        for(int i = 1; i < h.size(); i++) {
            h[i] = (h[i - 1] * 1ll * p + s[i - 1] - 'a') % M;
        }
    }

    int get(int l, int r) {
//        cout << "get " << l << ' ' << r << ' ' << h[l] << ' ' << h[r] << ' ' << pw[r- l] << endl;
        return (h[r] - h[l] * 1ll * pw[r - l] % M + M) % M;
    }
};

const int M = 1e9 + 7;


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    Hash_str h(s);
//    cout << "gdf" << endl;

    vector<int> a(m);
    vector<bool> b(n, false);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]] = true;
    }

    int lst = -1;
    int ans = 1;
    for(int i = 0; i < n; i++) {
        if(b[i]) {
            if(lst == -1 || h.get(i - lst, s.size()) == h.get(0, lst + s.size() - i)) {
                lst = i;
            } else {
//                cout << i - lst << ' ' << lst + s.size() - i << endl;
//                cout << h.get(i - lst, s.size()) << ' '<< h.get(0, lst + s.size() - i) << endl;
                cout << 0 << endl;
                return 0;
            }
        }

        if(i - lst == s.size())
            lst = -1;

        if(lst == -1)
            ans = ans * 1ll * A % M;
    }

    cout << ans;
}