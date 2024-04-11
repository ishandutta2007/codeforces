#include<bits/stdc++.h>
#define f first
#define s second.first
using namespace std;
int n, m, p, t, r;
vector < pair < int , pair < int , int > > > A[1000000];
pair < int , pair < int , int > > T;
priority_queue < pair < int , pair < int , int > > > P, Q, S;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &p, &t, &r);
        T.f = i;
        T.s = r;
        T.second.second = 1;
        A[p].push_back(T);
        T.second.second = 2;
        A[t].push_back(T);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            A[i][j].f *= -1;
            if (A[i][j].second.second == 1)
            {
                P.push(A[i][j]);
            }
            else
            {
                Q.push(A[i][j]);
            }
        }
        T = P.top();
        while (P.size() > 0)
        {
            if (P.top().s != i)
                break;
            S.push(P.top());
            P.pop();
        }
        if (P.size() == 0)
        {
            printf("0 ");
        }
        else
        {
            printf("%d ", P.top().s);
        }
        while (S.size() > 0)
        {
            P.push(S.top());
            S.pop();
        }
        while (Q.size() > 0)
        {
            if (P.top().f != Q.top().f)
            {
                break;
            }
            else
            {
                P.pop();
                Q.pop();
            }
        }
    }
    return (0);
}