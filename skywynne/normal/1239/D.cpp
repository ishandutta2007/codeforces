// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, q, P[N], qu[N], M[N];
vector < int > Adj[N];
int Find(int v)
{
    if (P[v] < 0)
        return (v);
    return (P[v] = Find(P[v]));
}
int main()
{
    scanf("%d", &q);
    for (; q; q --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n + n; i ++)
            P[i] = -1, Adj[i].clear();
        for (int i = 1; i <= m; i ++)
        {
            int a, b;
            scanf("%d%d", &a, &b); b += n;
            Adj[a].push_back(b);
            Adj[b].push_back(a);
            if (Find(a) == Find(b))
                continue;
            a = Find(a);
            b = Find(b);
            P[b] = a;
        }
        vector < int > vec;
        for (int i = 1; i <= n + n; i ++)
            if (P[i] == -1)
                vec.push_back(i);
        if (vec.size() == 1)
        {
            for (int i = 1; i <= n + n; i ++)
                M[i] = 0;
            int l = 0, r = 0;
            qu[r ++] = 1;
            M[1] = 1;
            while (r - l)
            {
                int v = qu[l ++];
                for (int u : Adj[v])
                    if (!M[u - n])
                        M[u - n] = 1, qu[r ++] = u - n;
            }
            if (r != n)
            {
                vector < int > A, B;
                for (int i = 1; i <= n; i ++)
                {
                    if (M[i]) A.push_back(i);
                    else B.push_back(i);
                }
                printf("Yes\n%d %d\n", (int)A.size(), (int)B.size());
                for (int a : A) printf("%d ", a);
                printf("\n");
                for (int b : B) printf("%d ", b);
                printf("\n");
                continue;
            }
            for (int i = 1; i <= n + n; i ++)
                M[i] = 0;
            l = 0, r = 0;
            qu[r ++] = n + 1;
            M[n + 1] = 1;
            while (r - l)
            {
                int v = qu[l ++];
                for (int u : Adj[v])
                    if (!M[u + n])
                        M[u + n] = 1, qu[r ++] = u + n;
            }
            if (r != n)
            {
                vector < int > A, B;
                for (int i = n + 1; i <= n + n; i ++)
                {
                    if (M[i]) B.push_back(i - n);
                    else A.push_back(i - n);
                }
                printf("Yes\n%d %d\n", (int)A.size(), (int)B.size());
                for (int a : A) printf("%d ", a);
                printf("\n");
                for (int b : B) printf("%d ", b);
                printf("\n");
                continue;
            }
            printf("No\n")  ;
            continue;
        }
        vector < int > A, B;
        for (int i = 1; i <= n; i ++)
        {
            if (Find(i) == vec[0])
                A.push_back(i);
            else
                B.push_back(i);
        }
        printf("Yes\n%d %d\n", (int)A.size(), (int)B.size());
        for (int a : A) printf("%d ", a);
        printf("\n");
        for (int b : B) printf("%d ", b);
        printf("\n");
    }
    return 0;
}