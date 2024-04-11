#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

inline void add(int &a, int b) {
    a += b;
    if (a >= MD) a -= MD;
}

int main()
{
    string s;
    int n; cin >> n;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int cnt[256] = {0};
        for (int j = i; j < s.size(); ++j) {
            cnt[s[j]]++;
            if (cnt['U'] == cnt['D'] && cnt['R'] == cnt['L']) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}