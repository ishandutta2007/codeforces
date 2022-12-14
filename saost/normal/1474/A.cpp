#include <bits/stdc++.h>
#define REP(i, l, r) for(int i=l; i<r; i++)
#define FOR(i, l, r) for(int i=l; i<=r; i++)
#define REPD(i, r, l) for(int i=r-1; i>=l; i--)
#define N 100005

using namespace std;
int t, n;
char s[100005];

void Process() {
    int val1 = -1, val2;
    REP(i, 0, n) {
        val2 = (s[i] - '0') + 1;
        if (val1 == val2) val2--, putchar('0'); else putchar('1');
        val1 = val2;
    }
    putchar('\n');
}

void Enter() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, &s);
        Process();
    }
}

int main()
{
    Enter();
}