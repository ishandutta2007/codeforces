#include<bits/stdc++.h>
using namespace std;
int n, m, k, l, r, A[100010][5];
int Func(int c)
{
    if (c == 0)
    {
        return (1);
    }
    int q;
    long long t;
    deque < int > P[5];
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            while (P[j].size() > 0)
            {
                if (A[P[j].back()][j] < A[i][j])
                {
                    P[j].pop_back();
                    continue;
                }
                break;
            }
            P[j].push_back(i);
        }
    }
    for (int i = c - 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            while (P[j].size() > 0)
            {
                if (A[P[j].back()][j] < A[i][j])
                {
                    P[j].pop_back();
                    continue;
                }
                break;
            }
            P[j].push_back(i);
        }
        for (int j = 0; j < m; j++)
        {
            while(P[j].front() < i - c + 1)
                P[j].pop_front();
        }
        t = 0;
        for (int j = 0; j < m; j++)
        {
            t += A[P[j].front()][j];
        }
        if (t <= k)
        {
            return (1);
        }
    }
    return (0);
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if (k == 0)
    {
        for (int i = 0; i < m; i++)
            printf("0 ");
        return (0);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    l = 0;
    r = n + 1;
    while (r - l > 1)
    {
        if (Func((l + r) / 2) == 0)
        {
            r = (l + r) / 2;
        }
        else
        {
            l = (l + r) / 2;
        }
    }
    if (l == 0)
    {
        for (int i = 0; i < m; i++)
            printf("0 ");
        return (0);
    }
    int q;
    long long t;
    deque < int > P[5];
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            while (P[j].size() > 0)
            {
                if (A[P[j].back()][j] < A[i][j])
                {
                    P[j].pop_back();
                    continue;
                }
                break;
            }
            P[j].push_back(i);
        }
    }
    for (int i = l - 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            while (P[j].size() > 0)
            {
                if (A[P[j].back()][j] < A[i][j])
                {
                    P[j].pop_back();
                    continue;
                }
                break;
            }
            P[j].push_back(i);
        }
        for (int j = 0; j < m; j++)
        {
            while(P[j].front() < i - l + 1)
                P[j].pop_front();
        }
        t = 0;
        for (int j = 0; j < m; j++)
        {
            t += A[P[j].front()][j];
        }
        if (t <= k)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", A[P[j].front()][j]);
            }
            return (0);
        }
    }
    return (0);
}