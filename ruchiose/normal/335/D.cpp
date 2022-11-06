// Author: Ruchiose
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<stack>
#define i64 long long
#define d64 long double
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const int MAXN = 100010;
const int MAXA = 3000;
const int CNTA = MAXA + 10;

int N, U[MAXN], D[MAXN], L[MAXN], R[MAXN];
int bel[CNTA][CNTA], cnt[CNTA][CNTA];
int dBorder[CNTA][CNTA], rBorder[CNTA][CNTA];
int toLeft[CNTA][CNTA], toRight[CNTA][CNTA], toUp[CNTA][CNTA], toDown[CNTA][CNTA];

#define smatrix(arr, u, d, l, r) (arr[d][r] - arr[d][l] - arr[u][r] + arr[u][l])
#define lv(x, y) min(toLeft[x][y], toUp[x][y])
#define LV(x) lv(x.first, x.second)
#define hlv(x, y) min(toRight[x][y], toDown[x][y])
#define hLV(x) hlv(x.first, x.second)

void terminateWithYes(int x, int y, int l)
{
    vector<int> ret;
    ret.clear();
    int dx, dy;
    fortodo(dx, 1, l)
        fortodo(dy, 1, l)
            if (bel[x + dx][y + dy])
                ret.push_back(bel[x + dx][y + dy]);
    printf("YES %d\n", ret.size());
    int i;
    fortodo(i, 0, ret.size() - 1)
        printf("%d%s", ret[i], (i == ret.size() - 1) ? "\n" : " ");
    exit(0);
}

void chkFrame(int x, int y, int l)
{
    if (smatrix(cnt, x, x + l, y, y + l) == l * l)
        terminateWithYes(x, y, l);
}

typedef pair<int,int> PII;
vector<PII> _ULs[CNTA * 2], _DRs[CNTA * 2];
vector<PII> *UL = _ULs + CNTA, *DR = _DRs + CNTA;

bool operator < (const PII &x, const PII &y)
{
    return (x.first == y.first) ? (x.second < y.second) : (x.first < y.first);
}

int main()
{
    scanf("%d", &N);
    int i, j, x, y;
    fortodo(i, 0, MAXA)
        fortodo(j, 0, MAXA)
            bel[i][j] = cnt[i][j] = rBorder[i][j] = dBorder[i][j] = 0;
    fortodo(i, 1, N)
        {
            scanf("%d%d%d%d", &U[i], &L[i], &D[i], &R[i]);
            fortodo(x, U[i] + 1, D[i])
                fortodo(y, L[i] + 1, R[i])
                    cnt[x][y]++;
            bel[U[i] + 1][L[i] + 1] = i;
            fortodo(x, U[i] + 1, D[i])
                rBorder[x][L[i]] = rBorder[x][R[i]] = 1;
            fortodo(y, L[i] + 1, R[i])
                dBorder[U[i]][y] = dBorder[D[i]][y] = 1;
        }
    fortodo(i, 1, MAXA)
        fortodo(j, 1, MAXA)
            cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
    fortodo(i, 0, MAXA)
        fortodo(j, 0, MAXA)
            toUp[i][j] = (i) ? ((rBorder[i][j]) ? (toUp[i - 1][j] + 1) : 0) : 0;
    for (i = MAXA; i >= 0; i--)
        fortodo(j, 0, MAXA)
            toDown[i][j] = (i < MAXA) ? ((rBorder[i + 1][j]) ? (toDown[i + 1][j] + 1) : 0) : 0;
    fortodo(i, 0, MAXA)
        fortodo(j, 0, MAXA)
            toLeft[i][j] = (j) ? ((dBorder[i][j]) ? (toLeft[i][j - 1] + 1) : 0) : 0;
    fortodo(i, 0, MAXA)
        for (j = MAXA; j >= 0; j--)
            toRight[i][j] = (j < MAXA) ? ((dBorder[i][j + 1]) ? (toRight[i][j + 1] + 1) : 0) : 0;
    fortodo(i, -MAXA, MAXA)
        {
            UL[i].clear();
            DR[i].clear();
        }
    fortodo(i, 1, N)
        {
            UL[U[i] - L[i]].push_back(make_pair(U[i], L[i]));
            DR[D[i] - R[i]].push_back(make_pair(D[i], R[i]));
        }
    fortodo(i, -MAXA, MAXA)
        {
            sort(UL[i].begin(), UL[i].end());
            sort(DR[i].begin(), DR[i].end());
            stack<PII> drs;
            while (drs.size()) drs.pop();
            while ((UL[i].size()) || (DR[i].size()))
                if ((DR[i].size() == 0) || ((UL[i].size() != 0) && (UL[i].back().first >= DR[i].back().first)))
                    {
                        while ((drs.size()) && (drs.top().first - LV(drs.top()) > UL[i].back().first))
                            drs.pop();
                        if ((drs.size()) && (UL[i].back().first + hLV(UL[i].back()) >= drs.top().first))
                            chkFrame(UL[i].back().first, UL[i].back().second, drs.top().first - UL[i].back().first);
                        UL[i].pop_back();
                    }
                else
                    {
                        while ((drs.size()) && (drs.top().first - LV(drs.top()) >= DR[i].back().first - LV(DR[i].back())))
                            drs.pop();
                        drs.push(DR[i].back());
                        DR[i].pop_back();
                    }
        }
    printf("NO\n");
}