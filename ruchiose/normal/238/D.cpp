// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int Redirect = 23333;
const int Terminate = -1;

struct CHARACTER
{
    CHARACTER* s[2];
    int sig, id;
    CHARACTER()
    {
        s[0] = s[1] = NULL;
    }
};

void erase(CHARACTER* x)
{
    x->s[0]->s[1] = x->s[1];
    x->s[1]->s[0] = x->s[0];
    delete x;
}

int N, Q, Direction;
char ch[233333];

CHARACTER* C;

int char_to_sig(char ch)
{
    if (ch == '<') return Redirect + 0;
    if (ch == '>') return Redirect + 1;
    return ch - '0';
}

struct Log
{
    int loc, cnt[10];
};

Log logs[1333333];
int log0, visPrev[100010];

void Arv(CHARACTER* c)
{
    //printf("Arv %d\n", c->id);
    if ((c->s[0]) && (visPrev[c->id] == -1))
        visPrev[c->id] = c->s[0]->id;
}

void Evo(Log &l)
{
    //printf("%d(#%d), %d\n", C->sig, C->id, Direction);
    CHARACTER* rawC = C;
    if (C->sig >= Redirect)
        {
            C = C->s[Direction = C->sig - Redirect];
            if ((C->sig >= Redirect) || (C->sig == Terminate)) erase(rawC);
        }
    else
        {
            C = C->s[Direction];
            l.cnt[rawC->sig]++;
            if (rawC->sig == 0)
                erase(rawC);
            else
                rawC->sig--;        
        }
    Arv(C);
    l.loc = C->id;
    //printf("=>%d(#%d), %d\n", C->sig, C->id, Direction);
}

#include<vector>
vector<int> Vistime[100010];

int main()
{
    scanf("%d%d", &N, &Q);
    scanf("%s", ch + 1);
    C = new CHARACTER;
    C->id = 0; C->sig = Terminate;
    int i;
    fortodo(i, 1, N)
        {
            C->s[1] = new CHARACTER;
            C->s[1]->s[0] = C;
            C->s[1]->sig = char_to_sig(ch[i]);
            C->s[1]->id = i;
            C = C->s[1];
            visPrev[i] = -1;
        }
    C->s[1] = new CHARACTER;
    C->s[1]->s[0] = C;
    C->s[1]->sig = Terminate;
    C->s[1]->id = N + 1;
    while (C->s[0]) C = C->s[0];
    C = C->s[1]; Arv(C);
    logs[log0 = 0].loc = 1;
    Direction = 1;
    while (C->sig != Terminate)
        {
            while (C->sig != Terminate)
                {
                    logs[log0 + 1] = logs[log0];
                    log0++;
                    Evo(logs[log0]);
                }
            while (C->s[0]) C = C->s[0];
            C = C->s[1]; Arv(C);
            logs[log0 + 1] = logs[log0];
            log0++;
            logs[log0].loc = C->id;
            Direction = 1;
        }
    fortodo(i, 0, N + 1) Vistime[i].clear();
    fortodo(i, 0, log0)
        {
            Vistime[logs[i].loc].push_back(i);
            //printf("#%d = %d\n", i, logs[i].loc);
        }
    fortodo(i, 0, N + 1) Vistime[i].push_back(0x23333333);
    for (; Q; Q--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            #define Query(t, l) *lower_bound(Vistime[l].begin(), Vistime[l].end(), t)
            int t0 = Query(0, l);
            int t1 = min(Query(t0 + 1, visPrev[l]), Query(t0 + 1, r + 1));
            fortodo(i, 0, 9)
                printf("%d%s", logs[t1].cnt[i] - logs[t0].cnt[i], (i == 9) ? "\n" : " ");
        }
}