#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, diff = 0, freeLeft = 0, freeRight = 0;
    string s;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        diff += s[i] == ')' ? 1 : -1;
        freeLeft += s[i] == '(';
        if (s[i] == ')') {
            if (freeLeft > 0)
                freeLeft--;
            else
                freeRight++;
        }
    }

    if (diff != 0 || freeRight > 1)
        cout << "No\n";
    else
        cout << "Yes\n";

    return 0;
}