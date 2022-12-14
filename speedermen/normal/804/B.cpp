#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int go(string s) {
    int ans = 0;
    while (s.find("ab") != string::npos) {
        int pos = -1;
        for (int i = 0; ; ++i) {
            if (s[i] == 'a' && s[i + 1] == 'b') {
                pos = i;
                break;
            }
        }
        s.erase(s.begin() + pos);
        s.erase(s.begin() + pos);
        s.insert(s.begin() + pos, 'a');
        s.insert(s.begin() + pos, 'b');
        s.insert(s.begin() + pos, 'b');
        ans += 1;
    }
    return ans;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ca = 0, cb = 0, ans = 0;
    for (int i = (int)s.length() - 1; i >= 0; --i) {
        if (s[i] == 'a') {
            ans = (ans + cb) % MD;
            cb = (cb + cb) % MD;
        } else {
            cb = (cb + 1) % MD;
        }
    }
    cout << ans << endl;
    return 0;
}