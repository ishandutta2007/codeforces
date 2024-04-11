#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, numZero = 0, numOne = 0;
    string s;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        if (s[i] == 'z') numZero++;
        else if (s[i] == 'n') numOne++;
    }
    while (numOne--) cout << "1 ";
    while (numZero--) cout << "0 ";

    return 0;
}