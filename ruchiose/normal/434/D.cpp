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
const int MAXFN = 12000;
const int MAXFE = 150000;
const flow_size_type INF = 0x3FFFFFFF;

const int To_Posi = 350000;

int NS, NE, NC, S, T;
int head[MAXFN], e[MAXFE], enxt[MAXFE], ec;
flow_size_type cp[MAXFE];
int tag[MAXFN], lyr[MAXFN], Nid, cur[MAXFN], pre[MAXFN], prn[MAXFN];
flow_size_type supp[MAXFN], comp[MAXFN], ans;
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

int Y[55][205], a[55], b[55], c[55], l[55], r[55];
int N, M;

int f(int a, int b, int c, int x)
{
    return c + x * (b + x * a);
}

int main()
{
    scanf("%d%d", &N, &M);
    NS = 1; NE = 0;
    S = ++NE;
    T = ++NE;
    int i, j;
    fortodo(i, 1, N)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    fortodo(i, 1, N)
        {
            scanf("%d%d", &l[i], &r[i]);
            l[i] += 100;
            r[i] += 100;
        }
    fortodo(i, 1, N)
        fortodo(j, l[i], r[i] + 1)
            Y[i][j] = ++NE;
    sap_graph_init();
    fortodo(i, 1, N)
        {
            directed(S, Y[i][l[i]], INF);
            directed(Y[i][r[i] + 1], T, INF);
            fortodo(j, l[i], r[i])
                directed(Y[i][j], Y[i][j + 1], To_Posi - f(a[i], b[i], c[i], j - 100));
        }
    fortodo(i, 1, M)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            fortodo(j, l[u], r[u] + 1)
                if ((j - d >= l[v]) && (j - d <= r[v] + 1))
                    directed(Y[u][j], Y[v][j - d], INF);
        }
    sap_initialize();
    printf("%d\n", N * To_Posi - sap());
}