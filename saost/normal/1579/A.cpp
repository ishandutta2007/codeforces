#include <bits/stdc++.h>
using namespace std;
int t, n, sum;
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> s;
        sum = 0;
        for(char c : s) sum += (c == 'B' ? 1 : -1);
        cout << (sum == 0 ? "YES\n" : "NO\n");
    }
}