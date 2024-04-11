#include <cstdio>
#include <cstring>
#include <algorithm>

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int d[256];

int A, B;
char s[105];
int N;
int x[105], y[105];

int main()
{
    d['U'] = 0;
    d['R'] = 1;
    d['D'] = 2;
    d['L'] = 3;

    scanf("%d%d", &A, &B);
    scanf(" %s", s); N = strlen(s);
    
    x[0] = 0; y[0] = 0;
    for (int i = 0; i < N; i++) {
        x[i+1] = x[i] + dx[d[(int)s[i]]];
        y[i+1] = y[i] + dy[d[(int)s[i]]];
    }

    for (int i = 0; i < N; i++) {
        int X = A - x[i], Y = B - y[i];
        
        int xmove; 
        if (x[N] == 0) {
            if (X) continue;
            else xmove = -1;
        }
        else /* x[N] != 0 */ {
            if (X == 0) xmove = 0;
            else if ((x[N] < 0) != (X < 0)) continue;
            else if (std::abs(X) % std::abs(x[N]) != 0) continue;
            else xmove = X / x[N];
        }

        int ymove;
        if (y[N] == 0) {
            if (Y) continue;
            else ymove = -1;
        }
        else /* y[N] != 0 */ {
            if (Y == 0) ymove = 0;
            else if ((y[N] < 0) != (Y < 0)) continue;
            else if (std::abs(Y) % std::abs(y[N]) != 0) continue;
            else ymove = Y / y[N];
        }

        if (xmove == -1 || ymove == -1 || xmove == ymove) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
}