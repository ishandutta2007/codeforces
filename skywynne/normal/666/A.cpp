#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N], dp2[N], dp3[N];
string s;
set < string > S;
bool Check(int i, int j, int len)
{
    for (; len; len --, i++, j++)
        if (s[i] != s[j])
            return (1);
    return (0);
}
string get(int i, int len)
{
    string ret = "";
    for (; len ; len --, i++)
        ret += s[i];
    return (ret);
}
int main()
{
    cin >> s; n = s.size();
    s += ".......";
    dp2[n] = dp3[n] = 1;
    for (int i = n - 1; i >= 5; i--)
    {
        dp2[i] |= dp3[i + 2];
        dp3[i] |= dp2[i + 3];
        dp2[i] |= (dp2[i + 2] && (Check(i, i + 2, 2)));
        dp3[i] |= (dp3[i + 3] && (Check(i, i + 3, 3)));
        if (dp2[i])
            S.insert(get(i, 2));
        if (dp3[i])
            S.insert(get(i, 3));
    }
    cout << S.size() << '\n';
    for (auto X:  S)
        cout << X << '\n';
    return (0);
}