// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int n, m;
string S[N], T[N];
inline int row(string s)
{
    bool fail = 0;
    for (int i = 0; i < (int)s.size(); i ++)
        if (s[i] == 'P')
            fail = 1;
    if (!fail)
        return 0;
    if (s[0] == 'A' || s[(int)s.size() - 1] == 'A')
        return (1);
    for (int i = 0; i < (int)s.size(); i ++)
        if (s[i] == 'A')
            return (2);
    return (10);
}
inline int grid()
{
    int Mn = 10;
    bool fail = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            if (S[i][j] == 'P')
                fail = 1;
    if (!fail) return 0;
    Mn = min(row(S[0]), row(S[n - 1])) + 1;
    for (int i = 0; i < n; i ++)
        Mn = min(Mn, row(S[i]) + 2);
    return (Mn);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (; q; q --)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i ++)
            cin >> S[i];
        int Mn = grid();
        for (int j = 0; j < m; j ++)
            T[j] = "";
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                T[j] += S[i][j];
        for (int j = 0; j < m; j ++)
            S[j] = T[j];
        swap(n, m);
        Mn = min(Mn, grid());
        if (Mn > 4)
            printf("MORTAL\n");
        else
            printf("%d\n", Mn);
    }
    return 0;
}