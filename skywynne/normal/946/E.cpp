#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q;
string s, res;
bool Check(int n, int mask)
{
    if ((n - __builtin_popcount(mask)) & 1)
        return (0);
    if (n < __builtin_popcount(mask))
        return (0);
    int cc = 0;
    for (int i = 0; i < 10; i++)
        if (mask & (1 << i))
            res += char(i + '0'), cc ++;
    while (cc < n)
        res += '9', cc ++;
    return (1);
}
bool Solve(int n, int mask)
{
    bool w = 0;
    if (n < (int)s.size() - 1)
        w = Solve(n + 1, mask ^ (1 << (s[n] - '0')));
    if (w == 1)
    {
        res += s[n];
        return (1);
    }
    res = "";
    for (int i = (s[n] - '0' - 1); i >= 0; i--)
    {
        res = "";
        if (Check((int)s.size() - n - 1, mask ^ (1 << i)))
        {
            res += char(i + '0');
            return (1);
        }
    }
    return (0);
}
int main()
{
    cin >> q;
    while (q --)
    {
        cin >> s;
        int a = 0, b = 0;
        for (int i = 0; i < (int)s.size(); i++)
            a += (s[i] == '1'), b += (s[i] == '0');
        if (a + b == (int)s.size() && (a == 1 || (a == 2 && s[(int)s.size() - 1] == '1')))
        {
            for (int i = 0; i < (int)s.size() - 2; i++)
                cout << "9";
            cout << endl;
            continue;
        }
        res = "";
        Solve(0, 0);
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    return (0);
}