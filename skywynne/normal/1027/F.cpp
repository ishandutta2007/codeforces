#include<bits/stdc++.h>
using namespace std;
const int N = 1000006;
int n, cntv, cnte, A[N], B[N];
bool M[N * 2], P[N * 2];
vector < int > U, Adj[N * 2];
void DFS(int v)
{
    M[v] = 1; cntv ++;
    cnte += Adj[v].size();
    for (int &u : Adj[v])
        if (!M[u]) DFS(u);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &A[i], &B[i]);
        U.push_back(A[i]);
        U.push_back(B[i]);
    }
    sort(U.begin(), U.end());
    U.resize(unique(U.begin(), U.end()) - U.begin());
    for (int i = 0; i < n; i++)
    {
        A[i] = lower_bound(U.begin(), U.end(), A[i]) - U.begin();
        B[i] = lower_bound(U.begin(), U.end(), B[i]) - U.begin();
        Adj[A[i]].push_back(B[i]);
        Adj[B[i]].push_back(A[i]);
    }
    for (int i = (int)U.size() - 1; ~i; i --)
        if (!M[i])
        {
            cntv = cnte = 0;
            DFS(i); cnte >>= 1;
            if (cnte > cntv)
                return !printf("-1");
            if (cnte < cntv)
                P[i] = 1;
        }
    int Mn = U.size() - 1;
    for (; P[Mn]; Mn --);
    return !printf("%d", U[Mn]);
}