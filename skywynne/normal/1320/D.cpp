// Skywynne
#include<bits/stdc++.h>
using namespace std;
const int N = 200005, LG = 18, Mod = 1e9 + 9;
int n, m, q, A[N], Pw[N], PS[N];
pair < int , int > Hsh[LG][N];
vector < pair < int , int > > B;
string S;
inline pair < int , int > Merge(pair < int , int > hsha, pair < int , int > hshb)
{
    pair < int , int > hsh;
    hsh.first = (hsha.first + Pw[hsha.second] * 1LL * hshb.first) % Mod;
    hsh.second = hsha.second + hshb.second;
    return (hsh);
}
inline pair < int , int > GetHash(int l, int r)
{
    pair < int , int > hsh = {0, 0};
    for (int j = 0; j < LG; j ++)
        if ((r - l) >> j & 1)
            hsh = Merge(hsh, Hsh[j][l]), l += 1 << j;
    return (hsh);
}
inline pair < int , int > GetBlock(int l, int r)
{
    int c = S[l] - '0';
    int len = r - l;
    if (c == 1 && len % 2 == 0)
        return make_pair(0, 0);
    if (c == 1 && len % 2 == 1)
        return make_pair(0, 1);
    if (c == 0)
        return make_pair(len, 0);
}
inline pair < int , int > Get(int l, int r)
{
    if (PS[r - 1] - PS[l - 1] == r - l)
        return (make_pair(1, -1));
    if (PS[r - 1] - PS[l - 1] == 0)
        return (make_pair(0, -1));
    int le = lower_bound(B.begin(), B.end(), pair < int , int > {l, -1}) - B.begin();
    int ri = lower_bound(B.begin(), B.end(), pair < int , int > {r, -1}) - B.begin() - 1;
    if (B[ri].second > r)
        ri --;
    pair < int , int > hsh = GetHash(le, ri + 1);
    if (B[le].first > l)
        hsh = Merge(GetBlock(l, B[le].first), hsh);
    if (B[ri].second < r)
        hsh = Merge(hsh, GetBlock(B[ri].second, r));
    return (hsh);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> S;
    S = '#' + S;
    for (int i = 1; i <= n; i ++)
        PS[i] = PS[i - 1] + (S[i] == '1');
    for (int i = Pw[0] = 1; i < N; i ++)
        Pw[i] = Pw[i - 1] * 79193591LL % Mod;
    for (int i = 1; i <= n;)
    {
        int j = i;
        while (j <= n && S[j] == S[i])
            j ++;
        B.push_back({i, j});
        i = j;
    }
    int m = (int)B.size();
    for (int i = 0; i < m; i ++)
    {
        int c = A[B[i].first] - '0';
        Hsh[0][i] = GetBlock(B[i].first, B[i].second);
    }
    for (int j = 1; j < LG; j ++)
        for (int i = 0; i + (1 << j) <= m; i ++)
            Hsh[j][i] = Merge(Hsh[j - 1][i], Hsh[j - 1][i + (1 << (j - 1))]);
    cin >> q;
    for (int i = 1; i <= q; i ++)
    {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        int cc1 = PS[l1 + len - 1] - PS[l1 - 1];
        int cc2 = PS[l2 + len - 1] - PS[l2 - 1];
        if (cc1 != cc2)
            {printf("No\n"); continue;}
        if (Get(l1, l1 + len) == Get(l2, l2 + len))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}