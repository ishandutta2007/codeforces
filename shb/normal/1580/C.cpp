#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
int x[200010], y[200100];
int d[200010];
const int B = 450;
int st[200010];
int d2[B][B];

int S = 0;

void long_add(int pos, int X, int Y, int sgn) {
    while(pos <= m) {
        pos += X;
        if (pos <= m) d[pos] += sgn;
        pos += Y;
        if (pos <= m) d[pos] -= sgn;
    }
}

void short_add(int pos, int X, int Y, int sgn) {
    int MO = X + Y;
    int now = pos % MO;
    //printf("add %d %d %d\n",MO,(pos + X) % MO,(pos + X + Y) % MO);
    d2[MO][(pos + X) % MO] += sgn;
    d2[MO][(pos + X + Y) % MO] -= sgn;
}

int effect(int pos, int X, int Y, int now_pos) {
    int delta = now_pos - pos;
    if (delta % (X + Y) <= X - 1) return 0;
    return 1;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    for (int i = 1; i <= m; i++) {
        int op, k;
        scanf("%d%d",&op,&k);

        S += d[i];
        for (int j = 2; j < B; j++) {
            S += d2[j][i % j];
        }

        if (op == 2) {
            int X = x[k], Y = y[k];
            if (X + Y >= B) {
                long_add(st[k], X, Y, -1);
            } else {
                short_add(st[k], X, Y, -1);
            }
            int eff = effect(st[k], X, Y, i);
            //printf("erase %d\n",eff);
            S -= eff;
        }

        if (op == 1) {
            int X = x[k], Y = y[k];
            st[k] = i;
            if (X + Y >= B) {
                long_add(st[k], X, Y, 1);
            } else {
                short_add(st[k], X, Y, 1);
            }
        } 
        
        printf("%d\n",S);
    }
}