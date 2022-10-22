#include <bits/stdc++.h>

using namespace std;

vector<bool> r(10, false);

void el() {
    for (int i = 0; i < 10; i++) {
        if (r[i])
            continue;
        r[i] = true;
        break;
    }
}

void er() {
    for (int i = 9; i >= 0; i--) {
        if (r[i])
            continue;
        r[i] = true;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    char c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 'L')
            el();
        else if (c == 'R')
            er();
        else
            r[c - '0'] = false;
    }
    for (int i = 0; i < 10; i++) {
        if (r[i])
            cout << '1';
        else
            cout << '0';
    }
    cout << '\n';
    return 0;
}