#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define sc first
#define loc second

int b, d, a, c;
char A[110], C[110];

struct trans
{
    pii T[110];
    void init()
    {
        int i;
        fortodo(i, 0, c - 1) T[i] = mp(0, i);
    }
    void scan(char ch)
    {
        int i;
        fortodo(i, 0, c - 1)
            {
                if (ch == C[T[i].loc + 1])
                    T[i].loc++;
                if (T[i].loc == c)
                    {
                        T[i].loc = 0;
                        T[i].sc++;
                    }
            }
    }
    trans operator + (trans snd)
    {
        trans ret;
        int i;
        fortodo(i, 0, c - 1)
            {
                ret.T[i].loc = snd.T[T[i].loc].loc;
                ret.T[i].sc = snd.T[T[i].loc].sc + T[i].sc;
            }
        return ret;
    }
};

trans bas, ans;

int main()
{
    scanf("%d%d", &b, &d);
    scanf("%s%s", A + 1, C + 1);
    a = strlen(A + 1);
    c = strlen(C + 1);
    bas.init();
    ans.init();
    int i;
    fortodo(i, 1, a) bas.scan(A[i]);
    for (; b; b >>= 1)
        {
            if (b & 1) ans = ans + bas;
            bas = bas + bas;
        }
    printf("%d\n", ans.T[0].sc / d);
}