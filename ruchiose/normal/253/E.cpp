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

const int MAXN = 50010;

int N, toj;
int T[MAXN], S[MAXN], P[MAXN];
i64 Ti;

#include<vector>
vector<int> ops, abos;

vector<int> toAdd;
#include<map>

bool cmpAddOrderAZ(int x, int y)
{
    return T[x] < T[y];
}

map<int,int> Queue;
int pend[MAXN];

i64 completeTime[MAXN];

void Simulate()
{
    toAdd.clear();
    int i;
    fortodo(i, 1, N) toAdd.push_back(i);
    sort(toAdd.begin(), toAdd.end(), cmpAddOrderAZ);
    vector<int>::iterator nxtAdd = toAdd.begin();
    Queue.clear();
    i64 Present = 0;
    while ((nxtAdd != toAdd.end()) || (Queue.size()))
        {
            int nxtTimePiece = 1 << 30;
            if (Queue.size())
                nxtTimePiece = min(nxtTimePiece, pend[Queue.begin()->second]);
            if (nxtAdd != toAdd.end())
                nxtTimePiece = min(nxtTimePiece, int(T[*nxtAdd] - Present));
            Present += nxtTimePiece;
            if ((Queue.size()) && ((pend[Queue.begin()->second] -= nxtTimePiece) == 0))
                {
                    completeTime[Queue.begin()->second] = Present;
                    Queue.erase(Queue.begin());
                }
            if ((nxtAdd != toAdd.end()) && (T[*nxtAdd] == Present))
                {
                    pend[*nxtAdd] = S[*nxtAdd];
                    Queue.insert(make_pair(-P[*nxtAdd], *nxtAdd));
                    nxtAdd++;
                }
        }
}

void Reply(int px)
{
    printf("%d\n", px);
    int i;
    fortodo(i, 1, N) printf("%I64d%s", completeTime[i], (i == N) ? "\n" : " ");
    exit(0);
}

int main()
{
freopen("input.txt", "r", stdin);
freopen("output.txt","w",stdout);
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N) scanf("%d%d%d", &T[i], &S[i], &P[i]);
    scanf("%I64d", &Ti);
    fortodo(i, 1, N) if (P[i] == -1) toj = i;
    ops.clear();
    fortodo(i, 1, N)
        if (P[i] != -1)
            ops.push_back(P[i]);
    sort(ops.begin(), ops.end());
    abos.clear();
    abos.push_back(1);
    for (vector<int>::iterator it = ops.begin(); it != ops.end(); it++)
        if (abos.back() == *it)
            abos.back()++;
        else
            abos.push_back(*it + 1);
    int L = 0, R = abos.size() - 1;
    while (L <= R)
        {
            int Mid = (L + R) / 2;
            P[toj] = abos[Mid];
            Simulate();
            if (completeTime[toj] == Ti)
                Reply(abos[Mid]);
            if (completeTime[toj] < Ti)
                R = Mid - 1;
            else
                L = Mid + 1;
        }
    printf("-1\n");
}