#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, S, ANS[100010], TA[100010], i, j, bi, ci;
#define _x first
#define _y second
#define pii pair<int,int>
#define ppii pair<int, pii>
ppii s[100010];
pii g[100010];

bool cmpy(pii a, pii b) {return a._y < b._y;}
bool cmpyx(ppii a, ppii b) {return a._y._x < b._y._x;}
bool cmpyy(ppii a, ppii b) {return a._y._y < b._y._y;}

ppii H[100010]; int H0;
void Init() {H0 = 0;}
void Rise(int Nid)
{
    if (Nid == 1) return;
    int Fid = Nid / 2;
    if (cmpyy(H[Nid], H[Fid]))
        {
            swap(H[Nid], H[Fid]);
            Rise(Fid);
        }
}

void Fall(int Nid)
{
    if (Nid * 2 > H0) return;
    int Sid = Nid * 2;
    if ((Sid < H0) && (cmpyy(H[Sid + 1], H[Sid]))) Sid++;
    if (cmpyy(H[Sid], H[Nid]))
        {
            swap(H[Nid], H[Sid]);
            Fall(Sid);
        }
}

void Push(ppii &x)
{
    H0++;
    H[H0] = x;
    Rise(H0);
}

ppii Pop()
{
    ppii ret = H[1];
    H[1] = H[H0]; H0--;
    Fall(1);
    return ret;
}

bool Chk(int Time)
{
    int budget = S;
    Init();
    int pts = N;
    int ptb = M;
    int increment, i;
    while (ptb > 0)
        {
            for (; (pts) && (s[pts]._y._x >= g[ptb]._y); pts--) Push(s[pts]);
            if (H0 == 0) return false;
            ppii solver = Pop();
            if (budget < solver._y._y) return false;
            budget -= solver._y._y;
            increment = min(ptb, Time);
            fortodo(i, 1, increment)
                {
                    TA[g[ptb]._x] = solver._x;
                    ptb--;
                }
        }
    return true;
}

int main()
{
    scanf("%d%d%d", &N, &M, &S);
    fortodo(i, 1, M) scanf("%d", &g[i]._y);
    fortodo(i, 1, M) g[i]._x = i;
    fortodo(i, 1, N) scanf("%d", &s[i]._y._x);
    fortodo(i, 1, N) scanf("%d", &s[i]._y._y);
    fortodo(i, 1, N) s[i]._x = i;
    sort(g + 1, g + M + 1, cmpy);
    sort(s + 1, s + N + 1, cmpyx);
    int L = 0; int R = M + 1;
    while (R - L > 1) // R: yes, L: no
        {
            int Mid = (L + R) / 2;
            if (Chk(Mid))
                {
                    R = Mid;
                    fortodo(i, 1, M) ANS[i] = TA[i];
                }
            else
                L = Mid;
        }
    if (R == M + 1)
        printf("NO\n");
    else
        {
            printf("YES\n");
            fortodo(i, 1, M) printf("%d%s", ANS[i], (i == M) ? "\n" : " ");
        }
}