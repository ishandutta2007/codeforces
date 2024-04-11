#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 300010;

int N, p, i, j, D[MAXN];
i64 ANS = 0;

int Ds[MAXN];

const int FIELD = 2333333;

struct Unordered_Multiset
{
    i64 Alloc[FIELD];
    int Val[FIELD], Indices[FIELD], Size;
    void Init()
    {
        Size = 0;
        int i;
        fortodo(i, 0, FIELD - 1) Val[i] = 0;
    }
    void Release()
    {
        while (Size) Val[Indices[Size--]] = 0;
    }
    void Insert(i64 x) 
    {
        int Hv = x % FIELD;
        while ((Val[Hv]) && (Alloc[Hv] != x)) Hv = (Hv * 233 + 23333) % FIELD;
        Alloc[Hv] = x;
        if (Val[Hv] == 0) Indices[++Size] = Hv; 
        Val[Hv]++;
    }
};

Unordered_Multiset um;

int main()
{
    scanf("%d%d", &N, &p);
    fortodo(i, 1, N) D[i] = 0;
    um.Init();
    fortodo(i, 1, N)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (u > v) swap(u, v);
            D[u]++; D[v]++;
            um.Insert((((i64)u) << 32) + v);
        }
    i64 ANS = 0;
    fortodo(i, 1, N) Ds[i] = D[i];
    sort(Ds + 1, Ds + N + 1);
    for (i = N, j = 1; i > j; i--)
        {
            while ((j < i) && (Ds[i] + Ds[j] < p)) j++;
            ANS += i - j;
        }
    fortodo(i, 1, um.Size)
        {
            int u = um.Alloc[um.Indices[i]] >> 32;
            int v = (um.Alloc[um.Indices[i]] << 32) >> 32;
            int w = um.Val[um.Indices[i]];
            if ((D[u] + D[v] >= p) && (D[u] + D[v] - w < p)) ANS--;
        }
    cout << ANS << endl;
}