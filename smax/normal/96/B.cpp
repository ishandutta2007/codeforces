#include <bits/stdc++.h>
using namespace std;

int n;
string s, ret;

bool dfs(int idx, int four, int seven, bool flag) {
    if (idx == n)
        return true;

    if (flag) {
        for (int i=0; i<four; i++)
            ret[idx+i] = '4';
        for (int i=four; i<four+seven; i++)
            ret[idx+i] = '7';
        return true;
    }

    if (four > 0 && s[idx] <= '4' && dfs(idx + 1, four - 1, seven, s[idx] < '4')) {
        ret[idx] = '4';
        return true;
    }

    if (seven > 0 && s[idx] <= '7' && dfs(idx + 1, four, seven - 1, s[idx] < '7')) {
        ret[idx] = '7';
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> s;
    n = s.length();
    ret.resize(n);

    if (n % 2 == 1 || !dfs(0, n / 2, n / 2, false)) {
        int half = (n + 2) / 2;
        for (int i=0; i<half; i++)
            cout << '4';
        for (int i=0; i<half; i++)
            cout << '7';
        cout << "\n";
    } else
        cout << ret << "\n";

    return 0;
}