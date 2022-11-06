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

#define right righ233

struct Interval
{
    int L, R, rId;
    bool neighbor(Interval rhs)
    {
        return max(L, rhs.L) <= min(R, rhs.R);
    }
};

bool operator < (Interval lhs, Interval rhs)
{
    return (lhs.R == rhs.R) ? ((lhs.L == rhs.L) ? (lhs.rId < rhs.rId) : (lhs.L < rhs.L)) : (lhs.R < rhs.R);
}

int N;
Interval itr[2010], ret[2010];
int rIndex[2010], rCount;

bool drawn[2010];

#include<set>
#include<vector>
set<Interval> gamma;
vector<Interval> undrawn;

bool BANDWIDTH(int K)
{
    //printf("BW %d\n", K);
    int i, j;
    fortodo(i, 1, N) ret[i] = itr[i];
    sort(ret + 1, ret + N + 1);
    fortodo(i, 1, N) // iterate
        {
            //fortodo(j, 1, N) printf("%d%s", ret[j].rId, (j == N) ? "\n" : " ");
            rCount = 0;
            fortodo(j, i + 1, N)
                if (ret[i].neighbor(ret[j]))
                    rIndex[++rCount] = j;
            fortodo(j, i + 1, N) drawn[j] = false;
            /*
            printf("r: "); fortodo(j, 1, rCount) printf("%d<%d> ", right[j].rId, rIndex[j]);
            printf("\nn: "); fortodo(j, 1, nCount) printf("%d ", non_neighbor[j].rId);
            puts("");
            */
            if (rCount > K) return false;
            if (rIndex[rCount] <= i + K) continue;
            gamma.clear();
            fortodo(j, 1, rCount)
                if (rIndex[j] > i + K - (rCount - j))
                    {
                        gamma.insert(ret[rIndex[j]]);
                        drawn[rIndex[j]] = true;
                    }
            undrawn.clear();
            fortodo(j, i + 1, N)
                if (!drawn[j])
                    undrawn.push_back(ret[j]);
            int lpos = i + K + 1 - gamma.size();
            fortodo(j, lpos, i + K)
                {
                    Interval toPut;
                    if (gamma.count(ret[j]))
                        toPut = ret[j];
                    else
                        toPut = *gamma.begin();
                    ret[j] = toPut;
                    gamma.erase(ret[j]);
                }
            vector<Interval>::iterator it = undrawn.begin();
            fortodo(j, i + 1, N)
                {
                    if ((j >= lpos) && (j <= i + K)) continue;
                    ret[j] = *it;
                    it++;
                }
        }
    return true;
}

void correctedKratsch()
{
    int L = 0, R = N;
    while (R - L > 1)
        {
            int Mid = (L + R) / 2;
            if (BANDWIDTH(Mid))
                R = Mid;
            else
                L = Mid;
        }
    BANDWIDTH(R);
    int i;
    fortodo(i, 1, N) printf("%d%s", ret[i].rId, (i == N) ? "\n" : " ");
}

int main()
{
    scanf("%d", &N);
    int i;
    fortodo(i, 1, N)
        {
            scanf("%d%d", &itr[i].L, &itr[i].R);
            itr[i].rId = i;
        }
    correctedKratsch();
}