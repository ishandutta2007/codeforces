#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j, u, v, e[200001][2], enxt[200001], head[100001], ec;
char Rank[100001];

void Regi(int u, int v)
{
    ec++;
    e[ec][0] = u; e[ec][1] = v;
    enxt[ec] = head[u]; head[u] = ec;
}

int Sz[100010];

void Getsize(int Nid)
{
    Rank[Nid] = '-';
    Sz[Nid] = 1;
    int E;
    for (E = head[Nid]; E; E = enxt[E])
        if (Rank[e[E][1]] == '\0')
            {
                Getsize(e[E][1]);
                Sz[Nid] += Sz[e[E][1]];
            }
    Rank[Nid] = '\0';
}

void Coloring(int Nid, char Color)
{
    Getsize(Nid);
    int Majsub, Majsize, c;
    Majsub = Nid;
    do
        {
            c = Majsub;
            Majsub = Majsize = 0;
            for (int E = head[c]; E; E = enxt[E])
                if ((Rank[e[E][1]] == '\0') && (Sz[e[E][1]] < Sz[c])
                    && (Sz[e[E][1]] > Majsize))
                    {
                        Majsize = Sz[e[E][1]];
                        Majsub = e[E][1];
                    }
        }
    while (Majsize * 2 > Sz[Nid]);
    Rank[c] = Color;
    for (int E = head[c]; E; E = enxt[E])
        if (Rank[e[E][1]] == '\0')
            Coloring(e[E][1], Color + 1);
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 2, N)
        {
            scanf("%d%d", &u, &v);
            Regi(u, v); Regi(v, u);
        }
    fortodo(i, 1, N) Rank[i] = '\0';
    Coloring(1, 'A');
    fortodo(i, 1, N)
        printf("%c%s", Rank[i], (i == N) ? "\n" : " ");
}