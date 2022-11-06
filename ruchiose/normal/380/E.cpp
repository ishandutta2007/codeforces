#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, i, j, B[300010];

pair<int,int> U[300010];
int W[300010];

bool Cmp_pii(pair<int,int> p, pair<int,int> q)
{
    if (p.first != q.first)
        return (p.first > q.first);
    else
        return (p.second < q.second);
}

const int DEP = 60;
d64 Rate[DEP + 5], ANS, Lc, Rc;

int L[300010], R[300010], x, y;

void Delete_element(int x)
{
    L[R[x]] = L[x];
    R[L[x]] = R[x];
}

int main()
{
    scanf("%d", &N);
    fortodo(i, 1, N) scanf("%d", &B[i]);
    Rate[0] = 1;
    fortodo(i, 1, DEP) Rate[i] = Rate[i - 1] / 2;
    fortodo(i, 1, N) U[i] = make_pair(B[i], i);
    sort(U + 1, U + N + 1, Cmp_pii);
    fortodo(i, 1, N) W[U[i].second] = i;
    ANS = 0;
    fortodo(i, 0, N)
        {
            R[i] = i + 1;
            L[i + 1] = i;
        }
    for (i = N; i; i--)
        {
            int w = U[i].second;
            x = y = w;
            Lc = Rc = 0;
            fortodo(j, 0, DEP)
                {
                    if (x >= 1)
                        {
                            Lc += Rate[j] * (x - L[x]);
                            x = L[x];
                        }
                    if (y <= N)
                        {
                            Rc += Rate[j] * (R[y] - y);
                            y = R[y];
                        }
                }
            Delete_element(w);
            ANS += 0.5 * Lc * Rc * (U[i].first);
        }
    ANS /= N;
    ANS /= N;
    printf("%.9f\n", double(ANS));
}