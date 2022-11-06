#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

//-----------------------------------------------------------------------
// TEMPLATE BEGIN HERE

typedef int flow_size_type;
const int MAXFN = 50000;
const int MAXFE = 550000;
const flow_size_type INF = 0x5FFFFFFF;

int NS, NE, NC, S, T;
int head[MAXFN], e[MAXFE], enxt[MAXFE], ec;
flow_size_type cp[MAXFE];
int tag[MAXFN], lyr[MAXFN], Nid, cur[MAXFN], pre[MAXFN], prn[MAXFN];
flow_size_type supp[MAXFE], comp[MAXFE], ans;
bool Gap; 

void regi(int u, int v, flow_size_type w)
{
    ec++;
    e[ec] = v; cp[ec] = w;
    enxt[ec] = head[u]; head[u] = ec;
}

void directed(int u, int v, flow_size_type w)
{
    regi(u, v, w);
    regi(v, u, 0);
}

void undirected(int u, int v, flow_size_type w)
{
    regi(u, v, w);
    regi(v, u, w);
}

void sap_graph_init()
{
    NC = NE - NS + 1;
    ec = 0;
    int i;
    fortodo(i, NS, NE) head[i] = 0; 
}

void push(int Eid, flow_size_type fs)
{
    cp[Eid] -= fs;
    cp[((Eid - 1) ^ 1) + 1] += fs;
}

void relabel(int x)
{
    int ol = tag[x];
    int nl = NC;
    for (int E = head[x]; E; E = enxt[E])
        if ((cp[E]) && (tag[x] <= tag[e[E]] + 1))
            nl = min(nl, tag[e[E]] + 1);
    lyr[nl]++; lyr[ol]--; tag[x] = nl;
    Gap |= (lyr[ol] == 0);
    cur[x] = head[x];
}

void sap_initialize()
{
    int i;
    fortodo(i, NS, NE)
        {
            tag[i] = lyr[i] = 0;
            cur[i] = head[i];
        }
    lyr[0] = NC;
    Nid = S; Gap = false;
    supp[Nid] = INF; comp[Nid] = 0;
}

flow_size_type sap()
{
    flow_size_type ans = 0;
    while ((tag[S] != NC) && (!Gap))
        {
            if (Nid == T)
                {
                    flow_size_type increment = supp[Nid] - comp[Nid];
                    ans += increment;
                    for (int x = T; x != S; x = prn[x])
                        {
                            comp[x] += increment;
                            push(pre[x], increment);
                        }
                }
            bool Aug = false;
            if (supp[Nid] > comp[Nid])
                for (; cur[Nid]; cur[Nid] = enxt[cur[Nid]])
                    {
                        int E = cur[Nid];
                        if ((cp[E]) && (tag[Nid] == tag[e[E]] + 1))
                            {
                                Aug = true;
                                supp[e[E]] = min(cp[E], supp[Nid] - comp[Nid]);
                                comp[e[E]] = 0;
                                prn[e[E]] = Nid;
                                pre[e[E]] = E;
                                Nid = e[E];
                                break;
                            }
                    }
            if (!Aug)
                {
                    if (Nid != T) relabel(Nid);
                    if (Nid == S)
                        comp[Nid] = 0;
                    else
                        Nid = prn[Nid];
                }
        }
    return ans;
}

// TEMPLATE END HERE
//-----------------------------------------------------------------------

const int MAXN = 10010;
const int MAXM = 2010;
int dog[MAXN], gfs[MAXM], inisex[MAXN];

int main()
{
    int N, M, g, tot = 0, i, j;
    scanf("%d%d%d", &N, &M, &g);
    NS = 1; NE = 0;
    S = ++NE; T = ++NE;
    fortodo(i, 1, N) dog[i] = ++NE;
    fortodo(i, 1, M) gfs[i] = ++NE;
    sap_graph_init();
    fortodo(i, 1, N) scanf("%d", &inisex[i]);
    fortodo(i, 1, N)
        {
            int v;
            scanf("%d", &v);
            if (inisex[i] == 0)
                directed(S, dog[i], v);
            else
                directed(dog[i], T, v);
        }
    fortodo(i, 1, M)
        {
            int a, w, k, isf, pi;
            scanf("%d%d%d", &a, &w, &k);
            tot += w;
            fortodo(j, 1, k)
                {
                    scanf("%d", &pi);
                    if (a == 0)
                        directed(gfs[i], dog[pi], INF);
                    else
                        directed(dog[pi], gfs[i], INF);
                }
            scanf("%d", &isf);
            w += isf * g;
            if (a == 0)
                directed(S, gfs[i], w);
            else
                directed(gfs[i], T, w);
        }
    sap_initialize();
    printf("%d\n", tot - sap());
}