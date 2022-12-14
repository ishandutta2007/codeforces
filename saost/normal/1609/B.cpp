#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
int n, q, x, dem;
char c;
string s;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q >> s;
    for(int i=0; i+2<n; ++i) if (s.substr(i, 3) == "abc") ++dem;
    while (q--) {
        cin >> x >> c; --x;
        if (x+3 <= n && s.substr(x, 3) == "abc") --dem;
        if (x+2 <= n && x-1 >= 0 && s.substr(x-1, 3) == "abc") --dem;
        if (x-2 >= 0 && s.substr(x-2, 3) == "abc") --dem;
        s[x] = c;
        if (s.substr(x, 3) == "abc") ++dem;
        if (x-1 >= 0 && s.substr(x-1, 3) == "abc") ++dem;
        if (x-2 >= 0 && s.substr(x-2, 3) == "abc") ++dem;
        cout << dem << '\n';
    }
}