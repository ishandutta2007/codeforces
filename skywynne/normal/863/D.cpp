// I'm back ...
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, m, q, A[N], L[N], R[N], T[N];
int TrackDown(int id, int j)
{
    if (!j) return (A[id]);
    if (id < L[j] || id > R[j])
        return TrackDown(id, j - 1);
    if (T[j] == 1 && id == L[j])
        return TrackDown(R[j], j - 1);
    if (T[j] == 1)
        return TrackDown(id - 1, j - 1);
    return TrackDown(L[j] + R[j] - id, j - 1);
}
int main()
{
    scanf("%d%d%d", &n, &q, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= q; i++)
        scanf("%d%d%d", &T[i], &L[i], &R[i]);
    for (int i = 1, id; i <= m; i++)
        scanf("%d", &id), printf("%d ", TrackDown(id, q));
    return (0);
}