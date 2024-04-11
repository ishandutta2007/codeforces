#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
#include<set>
using namespace std;

int N, M, Q, i, j, k, u;
set<int> Nei[50001];
bool online[50001];
int Primiedg[150001][2];

char Opt[2];
int op[250001][3];

#define pii pair<int,int>
bool cmpx(pii a, pii b) {return a.first > b.first;}

pii users[50001];
int prio[50001];
void Get_priority()
{
    int i;
    fortodo(i, 1, N) users[i] = make_pair(Nei[i].size(), i);
    sort(users + 1, users + N + 1, cmpx);
    fortodo(i, 1, N) prio[users[i].second] = i;
}

int ANS[50001];

int ec, e[400010], enxt[400010], head[50010];
bool active[400010];

void REGI(int u, int v)
{
    ec++;
    e[ec] = v; enxt[ec] = head[u];
    head[u] = ec; active[ec] = false;
}

void login(int u)
{
    online[u] = true;
    for (int E = head[u]; E; E = enxt[E])
        if (active[E])
            ANS[e[E]]++;
}

void logout(int u)
{
    online[u] = false;
    for (int E = head[u]; E; E = enxt[E])
        if (active[E])
            ANS[e[E]]--;
}

void add_friend(int u, int v)
{
    // v 
    if (prio[u] < prio[v]) swap(u, v);
    for (int E = head[u]; E; E = enxt[E])
        if (e[E] == v)
            active[E] = true;
    ANS[v] += (online[u]) ? 1 : 0;
}

void del_friend(int u, int v)
{
    if (prio[u] < prio[v]) swap(u, v);
    for (int E = head[u]; E; E = enxt[E])
        if (e[E] == v)
            active[E] = false;
    ANS[v] -= (online[u]) ? 1 : 0;  
}

int query(int u)
{
    int ans = ANS[u];
    for (int E = head[u]; E; E = enxt[E])
        if ((active[E]) && (online[e[E]]))
            ans++;
    return ans;
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    fortodo(i, 1, N) online[i] = false;
    scanf("%d", &k);
    fortodo(i, 1, k) 
        {
            scanf("%d", &u);
            online[u] = true;
        }
    fortodo(i, 1, M)
        scanf("%d%d", &Primiedg[i][0], &Primiedg[i][1]);
    fortodo(i, 1, N) Nei[i].clear();
    fortodo(i, 1, Q)
        {
            scanf("%s", Opt + 1);
            if ((Opt[1] == 'A') || (Opt[1] == 'D'))
                scanf("%d%d", &op[i][1], &op[i][2]);
            else
                scanf("%d", &op[i][1]);
            if (Opt[1] == 'O') op[i][0] = 0;
            if (Opt[1] == 'F') op[i][0] = 1;
            if (Opt[1] == 'A') op[i][0] = 2;
            if (Opt[1] == 'D') op[i][0] = 3;
            if (Opt[1] == 'C') op[i][0] = 4;
        }
    fortodo(i, 1, M)
        {
            Nei[Primiedg[i][0]].insert(Primiedg[i][1]);
            Nei[Primiedg[i][1]].insert(Primiedg[i][0]);
        }
    fortodo(i, 1, Q)
        if (op[i][0] == 2)
            {
                Nei[op[i][1]].insert(op[i][2]);
                Nei[op[i][2]].insert(op[i][1]);
            }
    Get_priority();
    ec = 0;
    fortodo(i, 1, N)
        {
            head[i] = 0;
            ANS[i] = 0;
            while (Nei[i].size())
                {
                    int front = *(Nei[i].begin());
                    if (prio[front] < prio[i])
                        REGI(i, front);
                    Nei[i].erase(front);
                }
        }
    fortodo(i, 1, M) add_friend(Primiedg[i][0], Primiedg[i][1]);
    fortodo(i, 1, Q)
        {
            if (op[i][0] == 0) login(op[i][1]);
            if (op[i][0] == 1) logout(op[i][1]);
            if (op[i][0] == 2) add_friend(op[i][1], op[i][2]);
            if (op[i][0] == 3) del_friend(op[i][1], op[i][2]);
            if (op[i][0] == 4)
                printf("%d\n", query(op[i][1]));
        }
}