// Skywynne
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5015, MXP = 705;
int n, C[N], LP[N], V[N][MXP], cur[MXP], nxt[N][MXP], vote[MXP];
vector < int > P;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    for (int i = 0, a; i < n; i ++)
        scanf("%d", &a), C[max(a, 1)] ++;
    memset(LP, -1, sizeof(LP));
    for (int i = 2; i < N; i ++)
        if (LP[i] == -1)
        {
            P.pb(i);
            for (int j = i; j < N; j += i)
                if (LP[j] == -1) LP[j] = (int)P.size() - 1;
        }
    int tsm = 0;
    long long tot = 0;
    vector < int > vec, tmp;
    for (int i = 1; i < N; i ++)
    {
        for (int j = 0; j < (int)P.size(); j ++)
            V[i][j] = V[i - 1][j];
        int a = i, cnt = 0;
        while (a > 1)
            V[i][LP[a]] ++, a /= P[LP[a]], cnt ++;
        tsm += cnt;
        tot += tsm * 1LL * C[i];
        if (C[i])
            vec.pb(i);
        int last = -1;
        for (int j = 0; j < (int)P.size(); j ++)
        {
            nxt[i][j] = last;
            if (V[i][j])
                last = j;
        }
    }
    int last = (int)P.size() - 1;
    while (true)
    {
        memset(vote, 0, sizeof(vote));
        for (int i : vec)
        {
            if (cur[last] < V[i][last])
                vote[last] += C[i];
            else if (nxt[i][last] != -1)
                vote[nxt[i][last]] += C[i];
        }
        int Mx = 0;
        for (int i = 0; i <= last; i ++)
            Mx = max(Mx, vote[i] - (n - vote[i]));
        if (Mx == 0)
            break;
        int opt = -1;
        for (int i = 0; i <= last; i ++)
            if (Mx == vote[i] - (n - vote[i]))
            {
                opt = i;
                break;
            }
        tot -= Mx;
        if (opt == last)
        {
            cur[last] ++;
            for (int i : vec)
                if (V[i][last] >= cur[last])
                    tmp.push_back(i);
            vec.swap(tmp);
            tmp.clear();
            continue;
        }
        cur[opt] ++;
        for (int i : vec)
            if (V[i][last] == cur[last] && nxt[i][last] == opt)
                tmp.push_back(i);
        vec.swap(tmp);
        tmp.clear();
        last = opt;
        continue;
    }
    printf("%lld\n", tot);
    return 0;
}