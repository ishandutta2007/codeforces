#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int F[100001];
int Setes[100001];
int Find(int x)
{
    if (x != F[x]) F[x] = Find(F[x]);
    return F[x];
}

int N, M, i, j, u, v;
int Dire[100001], e[200001][2], enxt[200001], head[100001], ec;
#define Enumerate(Nid, Eid) for (Eid = head[Nid]; Eid; Eid = enxt[Eid])

bool Thruable(int X)
{
    int G = (X + 1) >> 1;
    if (Dire[G] == 0)
        Dire[G] = X;
    return (Dire[G] == X);
}

void REGI(int u, int v)
{
    ec++;
    e[ec][0] = u; e[ec][1] = v;
    enxt[ec] = head[u]; head[u] = ec;
}

int Bitid[100001], Stamp;

pair<bool, pair<int,int> > DFS(int Nid, int Fid)
{
    if (Bitid[Nid]) return make_pair(true, make_pair(Fid, Nid));
    Bitid[Nid] = ++Stamp;
    int E;
    pair<bool, pair<int, int> > Present, Ret;
    Present = make_pair(false, make_pair(0, 0));
    Enumerate(Nid, E)
        if (Thruable(E))
            {
                Ret = DFS(e[E][1], Nid);
                if ((Ret.first) && (Present.first))
                    {
                        printf("%d %d %d\n", Present.second.second,
                                             Present.second.first,
                                             Ret.second.second);
                        Present = make_pair(false, make_pair(0, 0));
                        continue;
                    }
                if (Ret.first) Present = Ret;
            }
    if (Present.first)
        {
            printf("%d %d %d\n", Present.second.second, Nid, Fid);
            return make_pair(false, make_pair(0, 0));
        }
    else
        return make_pair(true, make_pair(Fid, Nid));
            
}

int main()
{
    scanf("%d%d", &N, &M);
    fortodo(i, 1, N) head[i] = 0; ec = 0;
    fortodo(i, 1, N) F[i] = i;
    fortodo(i, 1, M)
        {
            scanf("%d%d", &u, &v);
            REGI(u, v); REGI(v, u);
            F[Find(u)] = Find(v);
        }
    fortodo(i, 1, N) Setes[i] = 0;
    fortodo(i, 1, M) Setes[Find(e[i * 2][0])]++;
    fortodo(i, 1, N)
        if (Setes[i] & 1)
            {
                printf("No solution\n");
                return 0;
            }
    fortodo(i, 1, N) Bitid[i] = 0; Stamp = 0;
    fortodo(i, 1, N)
        if (F[i] == i)
            DFS(i, 0);
}