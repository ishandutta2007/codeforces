#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    string s;
    cin >> s;

    int cnt = 0;
    while(s.length() > 1) {
        int j = -1;
//        cout << s << endl;
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] != s[i + 1]) {
                j = i;
                break;
            }
        }

        if(j == -1)
            break;

        string s1 = "";
        for(int i = 0; i < j; i++)
            s1 += s[i];

        for(int i = j + 2; i < s.length(); i++)
            s1 += s[i];

        s = s1;
        cnt++;
    }

    cout << (cnt % 2 == 0 ? "NET" : "DA") << endl;
//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}