#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, r, c, P[30];
vector < int > V[30];
string s, t;
int Find(int nd)
{
    if (P[nd] < 0)
        return (nd);
    return (P[nd] = Find(P[nd]));
}
void Unite(int nd, int nt)
{
    nd = Find(nd);
    nt = Find(nt);
    if (nd == nt)
        return ;
    P[nt] += P[nd];
    P[nd] = nt;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s >> t;
    for (int i = 0; i < 26; i++)
        P[i] = -1;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i])
            Unite(s[i] - 'a', t[i] - 'a');
    for (int i = 0; i < 26; i++)
    {
        if (P[i] < 0)
            c += (-P[i] - 1);
    }
    cout << c << "\n";
    for (int i = 0; i < 26; i++)
    {
        if (P[i] < 0)
            V[i].push_back(i);
        else
            V[Find(i)].push_back(i);
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < (int)V[i].size() - 1; j++)
            cout << (char)(V[i][j] + 'a') << " " << (char)(V[i][j + 1] + 'a') << "\n";
    }
    return (0);
}