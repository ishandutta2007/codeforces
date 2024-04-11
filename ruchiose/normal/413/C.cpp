#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j;
int T[101], B[101], bi;

#define pii pair<int,int>
#define mp make_pair

pair<int,int> que[101];
i64 Sc;

bool cmp_pbata(pii a, pii b)
{
    return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);
}

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) scanf("%d", &T[i]);
    fortodo(i, 1, N) B[i] = 0;
    fortodo(i, 1, M)
        {
            scanf("%d", &bi);
            B[bi] = 1;
        }
    fortodo(i, 1, N)
        que[i] = mp(B[i], T[i]);
    sort(que + 1, que + N + 1, cmp_pbata);
    Sc = 0;
    fortodo(i, 1, N)
        if ((que[i].first == 1) && (Sc > que[i].second))
            Sc *= 2;
        else
            Sc += que[i].second;
    cout << Sc << endl;
}