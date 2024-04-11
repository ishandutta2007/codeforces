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

#include<set>
#include<vector>

int N, L, X, Y;
set<int> S;

vector<int> op;

void getAllPair(int delta)
{
    op.clear();
    for (set<int>::iterator it = S.begin(); it != S.end(); it++)
        if (S.count(*it + delta))
            op.push_back(*it);
}

int main()
{
    scanf("%d%d%d%d", &N, &L, &X, &Y);
    int i;
    S.clear();
    fortodo(i, 1, N)
        {
            int u;
            scanf("%d", &u);
            S.insert(u);
        }
    bool eX, eY;
    getAllPair(X);
    eX = (op.size() > 0);
    getAllPair(Y);
    eY = (op.size() > 0);
    if ((eX) && (eY))
        {
            printf("0\n");
            return 0;
        }
    if (eX)
        {
            printf("1\n%d\n", Y);
            return 0;
        }
    if (eY)
        {
            printf("1\n%d\n", X);
            return 0;
        }
    getAllPair(Y - X);
    for (vector<int>::iterator it = op.begin(); it != op.end(); it++)
        {
            if (*it >= X)
                {
                    printf("1\n%d\n", *it - X);
                    return 0;
                }
            if (*it + Y <= L)
                {
                    printf("1\n%d\n", *it + Y);
                    return 0;
                }
        }
    if (X + Y <= L)
        {
            getAllPair(X + Y);
            for (vector<int>::iterator it = op.begin(); it != op.end(); it++)
                {
                    printf("1\n%d\n", *it + X);
                    return 0;
                }
        }
    printf("2\n%d %d\n", X, Y);
}