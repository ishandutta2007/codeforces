#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, p;
string s, res;
bool eq, good;

bool check(int i, int ch) {
    string t = res;
    t += ('a' + ch);
   // cout << i << " " << (char)('a' + ch) << " " << t << endl;
    if(!eq || s[i] - 'a' != ch)
        return true;
    for(int j = i + 1; j < n; j++) {
        for(int ch2 = 0; ch2 < p; ch2++) {
            if(ch2 <= s[j] - 'a')
                continue;
            if(ch2 == t[j - 1] - 'a')
                continue;
            if(j > 1 && ch2 == t[j - 2] - 'a')
                continue;
            return true;
        }
        t += s[j];
    }
    return false;
}

void solve(int i) {
    for(int ch = 0; ch < p; ch++) {
        if(eq && ch < s[i] - 'a')
            continue;
        if(i && ch == res[i - 1] - 'a')
            continue;
        if(i > 1 && ch == res[i - 2] - 'a')
            continue;
        if(!check(i, ch))
            continue;
        res += ('a' + ch);
        if(ch != s[i] - 'a')
            eq = false;
        return;
    }
    good = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;
    eq = true;
    good = true;
    cin >> s;
    if(p == 1) {
        cout << "NO\n";
        return 0;
    }
    if(p == 2) {
        if(s == "a")
            cout << "b\n";
        else if(s == "b")
            cout << "NO\n";
        else if(s == "ab")
            cout << "ba\n";
        else
            cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
        solve(i);
    if(!good)
        cout << "NO\n";
    else
        cout << res << '\n';
}