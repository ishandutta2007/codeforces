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

const int MAXN = 100010;

#include<set>

typedef pair<int,int> PII;

bool operator < (PII lhs, PII rhs)
{
    return (lhs.first != rhs.first) ? (lhs.first < rhs.first) : (lhs.second < rhs.second);
}

set<PII> inqUp, inqDown, pendUp, pendDown;

int N, M, prsis, rci;
i64 T, Ans[MAXN];

struct User
{
    int id, ar, f, t;   
};

bool cmp_Useraraz (User lhs, User rhs)
{
    return lhs.ar < rhs.ar;
}

User u[MAXN], ru[MAXN];
int Where;

void Unload()
{
    while ((inqUp.size()) && (inqUp.begin()->first == Where))
        {
            Ans[inqUp.begin()->second] = T;
            inqUp.erase(inqUp.begin());
            rci++;
        }
    while (((inqDown.size()) && (--inqDown.end())->first == Where))
        {
            Ans[(--inqDown.end())->second] = T;
            inqDown.erase(--inqDown.end());
            rci++;
        }
}

void Request()
{
    while ((prsis != N) && (u[prsis + 1].ar == T))
        {
            prsis++;
            if (u[prsis].f >= Where)
                pendUp.insert(make_pair(u[prsis].f, u[prsis].id));
            else
                pendDown.insert(make_pair(u[prsis].f, u[prsis].id));
        }
}

void Load(int id)
{
    if (ru[id].t >= Where)
        inqUp.insert(make_pair(ru[id].t, id));
    else
        inqDown.insert(make_pair(ru[id].t, id));
}

void Load()
{
    while ((pendUp.size()) && (pendUp.begin()->first == Where))
        {
            Load(pendUp.begin()->second);
            pendUp.erase(pendUp.begin());           
        }
    while ((pendDown.size()) && ((--pendDown.end())->first == Where))
        {
            Load((--pendDown.end())->second);
            pendDown.erase(--pendDown.end());
        }
}

int main()
{
    scanf("%d%d", &N, &M);
    int i;
    fortodo(i, 1, N)
        {
            scanf("%d%d%d", &u[i].ar, &u[i].f, &u[i].t);
            u[i].id = i;
            ru[i] = u[i];
        }
    sort(u + 1, u + N + 1, cmp_Useraraz);
    inqUp.clear(); inqDown.clear();
    pendUp.clear(); pendDown.clear();
    Where = 1; T = 0;
    prsis = rci = 0;
    while (rci < N)
        {
            Unload();
            Request();
            Load();
            int pUp = inqUp.size() + pendUp.size();
            int pDown = inqDown.size() + pendDown.size();
            int Action = (pUp + pDown) ? ((pUp >= pDown) ? 1 : -1) : 0;
            int timePass = (prsis == N) ? M : (u[prsis + 1].ar - T);
            if (Action == 1) // Up
                {
                    if (pendUp.size()) timePass = min(timePass, pendUp.begin()->first - Where);
                    if (inqUp.size()) timePass = min(timePass, inqUp.begin()->first - Where);
                }
            if (Action == -1) // Down
                {
                    if (pendDown.size()) timePass = min(timePass, Where - (--pendDown.end())->first);
                    if (inqDown.size()) timePass = min(timePass, Where - (--inqDown.end())->first);
                }
            T += timePass;
            Where += timePass * Action;
        }
    fortodo(i, 1, N) printf("%I64d\n", Ans[i]);
}