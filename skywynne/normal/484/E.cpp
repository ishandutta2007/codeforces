#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q, A[N], P[N], le[N], ri[N], md[N], L[N], R[N], W[N], B[N];
struct Tuple {int a, b, c; Tuple(int _a = 0, int _b = 0, int _c = 0) {a = _a, b = _b, c = _c;}};
Tuple S[N * 4];
bool CMP(int i, int j) {return (A[i] > A[j]);}
bool CMP2(int i, int j) {return (md[i] < md[j]);}
void Add(int i, int id = 1, int l = 0, int r = n)
{
    if (r - l < 2)
    {
        S[id] = Tuple(1, 1, 1);
        return ;
    }
    int le = id * 2, ri = le + 1, mid = (l + r) >> 1;
    if (i < mid) Add(i, le, l, mid);
    else Add(i, ri, mid, r);
    S[id].a = max(max(S[le].a, S[ri].a), S[le].c + S[ri].b);
    S[id].b = S[le].b + (S[le].b == mid - l) * S[ri].b;
    S[id].c = S[ri].c + (S[ri].c == r - mid) * S[le].c;
}
Tuple Get(int ql, int qr, int id = 1, int l = 0, int r = n)
{
    if (qr <= l || r <= ql)
        return (Tuple(0, 0, 0));
    if (ql <= l && r <= qr)
        return (S[id]);
    int mid = (l + r) >> 1;
    Tuple lt = Get(ql, qr, id * 2, l, mid), rt = Get(ql, qr, id * 2 + 1, mid, r), ret;
    ret.a = max(max(lt.a, rt.a), lt.c + rt.b);
    ret.b = lt.b + (lt.b == mid - l) * rt.b;
    ret.c = rt.c + (rt.c == r - mid) * lt.c;
    return (ret);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]), P[i] = i;
    sort(P, P + n, CMP);
    scanf("%d", &q);
    for (int i = 0 ; i < q; i++)
        scanf("%d%d%d", &L[i], &R[i], &W[i]), le[i] = -1, ri[i] = n - 1, B[i] = i;
    for (int lp = 18; lp; lp --)
    {
        for (int i = 0; i < q; i++)
            md[i] = (le[i] + ri[i]) >> 1;
        for (int i = 0; i < N * 4; i++)
            S[i] = Tuple(0,0,0);
        sort(B, B + q, CMP2);
        int last = -1;
        for (int i = 0; i < q; i++)
        {
            while (last < md[B[i]])
                Add(P[++ last]);
            if (ri[B[i]] - le[B[i]] <= 1) continue;
            if (Get(L[B[i]] - 1, R[B[i]]).a >= W[B[i]])
                ri[B[i]] = md[B[i]];
            else
                le[B[i]] = md[B[i]];
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", A[P[ri[i]]]);
    return (0);
}