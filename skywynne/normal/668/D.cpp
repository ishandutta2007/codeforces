#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
int n, m, q, r, t, A[N], T[N], Tp[N];
vector < int > U, V;
map < int , int > MA, MT, F[N];
void Add(int j, int i, int val)
{
    for (; i < N; i += i & -i)
        F[j][i] += val;
}
int get(int j, int i)
{
    int ret = 0;
    for (; i; i -= i & -i)
        ret += F[j][i];
    return (ret);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &Tp[i], &T[i], &A[i]), U.pb(A[i]), V.pb(T[i]);
    U.pb(0); sort(U.begin(), U.end());
    U.resize(unique(U.begin(), U.end()) - U.begin());
    V.pb(0); sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 0; i < U.size(); i++)
        MA[U[i]] = i;
    for (int i = 0; i < V.size(); i++)
        MT[V[i]] = i;
    for (int i = 1; i <= n; i++)
    {
        A[i] = MA[A[i]];
        T[i] = MT[T[i]];
        if (Tp[i] == 1)
            Add(A[i], T[i], 1);
        if (Tp[i] == 2)
            Add(A[i], T[i], -1);
        if (Tp[i] == 3)
            printf("%d\n", get(A[i], T[i]));
    }
    return (0);
}