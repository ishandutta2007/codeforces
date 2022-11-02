#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10;
int n, c, B[N], T[N];
pair < int , int > A[N];
map < int , int > M;
vector < int > Odd;
vector < pair < int , int >  > V[N];
void Add(int v, int u, int i)
{
    V[v].push_back({u, i});
    V[u].push_back({v, i});
}
void DFS(int v)
{
    while (V[v].size())
    {
        auto X = V[v].back();
        V[v].pop_back();
        if (T[X.y])
            continue;
        T[X.y] = 1 + (v > X.x);
        DFS(X.x);
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &A[i].x, &A[i].y), B[i * 2] = A[i].x, B[i * 2 + 1] = A[i].y + 1;
    sort(B, B + 2 * n);
    for (int i = 0; i < 2 * n; i++)
        if (!M.count(B[i]))
            M[B[i]] = c ++;
    for (int i = 0; i < n; i++)
        Add(M[A[i].x], M[A[i].y + 1], i);
    for (int i = 0; i < c; i++)
        if (V[i].size() & 1)
            Odd.push_back(i);
    for (int i = 0; i < Odd.size(); i += 2)
        Add(Odd[i], Odd[i + 1], n + i / 2);
    for (int i = 0; i < c; i++)
        DFS(i);
    for (int i = 0; i < n; i++, putchar(' '))
        putchar(T[i] == 2 ? '1' : '0');
    return (0);
}