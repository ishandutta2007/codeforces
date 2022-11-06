#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cmath>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;

int B;
int N, M, Q, i, j, k;
i64 A[MAXN], Sum[MAXN], lazy[MAXN];
vector<int> S[MAXN], Intes[MAXN], Maj;
bool sgn[MAXN];

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    B = int(sqrt(N) + 0.1);
    fortodo(i, 1, N) scanf("%I64d", &A[i]);
    Maj.clear();
    fortodo(i, 1, M)
        {
            int si;
            scanf("%d", &si);
            if (si >= B) Maj.push_back(i);
            S[i].clear();
            fortodo(j, 1, si)
                {
                    int u;
                    scanf("%d", &u);
                    S[i].push_back(u);
                }
            lazy[i] = 0;
        }
    int mjc = Maj.size();
    fortodo(i, 1, N) sgn[i] = false;
    fortodo(i, 0, mjc - 1)
        {
            int us = Maj[i];
            int si = S[us].size();
            Intes[us].clear();
            Intes[us].push_back(0); //  
            fortodo(j, 0, si - 1) sgn[S[us][j]] = true;
            fortodo(k, 1, M)
                {
                    int cnt = 0, ssi = S[k].size();
                    fortodo(j, 0, ssi - 1)
                        if (sgn[S[k][j]])
                            cnt++;
                    Intes[us].push_back(cnt);
                }
            Sum[us] = 0;
            fortodo(j, 0, si - 1)
                {
                    sgn[S[us][j]] = false;
                    Sum[us] += A[S[us][j]];
                }
        }
    fortodo(i, 1, Q)
        {
            char Opt[2];
            int u, v, si;
            scanf("%s", Opt);
            if (Opt[0] == '?')
                {
                    scanf("%d", &u);
                    si = S[u].size();
                    i64 ans;
                    if (si >= B) // 
                        ans = Sum[u];
                    else
                        {
                            ans = 0;
                            fortodo(j, 0, si - 1)
                                ans += A[S[u][j]];
                        }
                    fortodo(j, 0, mjc - 1)
                        ans += lazy[Maj[j]] * Intes[Maj[j]][u];
                    cout << ans << endl;
                }
            else
                {
                    scanf("%d%d", &u, &v);
                    si = S[u].size();
                    if (si >= B)
                        lazy[u] += v;
                    else
                        {
                            fortodo(j, 0, si - 1)
                                A[S[u][j]] += v;
                            fortodo(j, 0, mjc - 1)
                                Sum[Maj[j]] += Intes[Maj[j]][u] * (i64)v;
                        }
                }
        }
}