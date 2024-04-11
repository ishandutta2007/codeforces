#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, Mx, B[N], S[N];
struct Node
{
    int32_t l, r, c;
    Node() {l = r = c = 0;}
};
struct BST
{
    int L = 32;
    vector < Node > A;
    BST(int _L = 32) {L = _L, A.clear(); A.push_back(Node());}
    void Add(int val, int w = 1)
    {
        int id = 0;
        for (int i = L - 1; ~i; i--)
        {
            A[id].c += w;
            if (val & (1ll << i))
            {
                if (!A[id].r)
                    A[id].r = A.size(), A.push_back(Node());
                id = A[id].r;
                continue;
            }
            if (!A[id].l)
                A[id].l = A.size(), A.push_back(Node());
            id = A[id].l;
        }
        A[id].c += w;
    }
    int MaxXor(int val)
    {
        int id = 0, ret = 0;
        if (!A[id].c)
            return (-1);
        for (int i = L - 1; ~i; i--)
        {
            if (A[id].r && (!A[id].l || !(val & (1ll << i))))
                ret |= (1ll << i), id = A[id].r;
            else
                id = A[id].l;
        }
        return (ret);
    }
};
int32_t main()
{
    scanf("%lld", &n);
    BST T = BST(43); T.Add(0);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &B[i]);
    for (int i = n; i; i--)
        S[i] = S[i + 1] ^ B[i], T.Add(S[i]);
    for (int i = 0, r = 0; i <= n; i++, r ^= B[i])
        Mx = max(Mx, T.MaxXor(r) ^ r), T.Add(S[i + 1], -1);
    return !printf("%lld", Mx);
}