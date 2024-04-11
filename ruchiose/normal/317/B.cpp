#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<deque>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int CB = 100;
const int DCB = CB << 1;
const int MAXB = DCB + 1;

int N, T, i, j;
int S[MAXB][MAXB];

#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second

deque<pii> s;

void putant(int a, int b, int c)
{
    S[a][b] += c;
    if ((S[a][b] - c < 4) && (S[a][b] >= 4))
        s.push_back(mp(a, b));
}

int main()
{
    scanf("%d%d", &N, &T);
    fortodo(i, 0, DCB)
        fortodo(j, 0, DCB)
            S[i][j] = 0;
    s.clear();
    putant(CB, CB, N);
    while (s.size())
        {
            int u, v;
            u = s.front().x;
            v = s.front().y;
            s.pop_front();
            putant(u - 1, v, S[u][v] / 4);
            putant(u + 1, v, S[u][v] / 4);
            putant(u, v - 1, S[u][v] / 4);
            putant(u, v + 1, S[u][v] / 4);
            S[u][v] %= 4;
        }
    fortodo(i, 1, T)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u += CB;
            v += CB;
            if ((u >= 0) && (u <= DCB) && (v >= 0) && (v <= DCB))
                printf("%d\n", S[u][v]);
            else
                printf("0\n");
        }
}