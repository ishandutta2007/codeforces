#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
int n;
string s;
int ans, k;
int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    cin >> s;

    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            ans++;
        else
            k++;
    cout << 1 + ans + min(2, k);


    return 0;
}