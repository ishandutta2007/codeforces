#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, r, t, p, c, A[N];
string s;
int main()
{
    cin >> s; n = (int)s.size();
    for (int i = 0; i < n && r < 26; i++)
    {
        if (s[i] - 'a' > r)
            continue;
        s[i] = (r + 'a'); r ++;
    }
    if (r != 26)
    {
        cout << -1;
        return (0);
    }
    cout << s;
    return (0);
}