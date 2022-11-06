#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

const string c[43] = 
{"000000","nil","nil","nil","000004","nil","nil",
"000007","000044","nil","nil","000047","000444","nil","000077","000447",
"004444","nil","000477","004447","044444","000777","004477",
"044447","444444","004777","044477","444447","007777","044777","444477",
"nil","047777","444777","nil","077777",
"447777","nil","nil","477777","nil","nil","777777"
};

i64 Possi[21][50];
i64 D[21], D0;

bool mainprocess(i64 n = 0)
{
    if (n) D[0] = n;
    else cin >> D[0];
    D0 = 0;
    while (D[D0] > 9)
        {
            D[D0 + 1] = D[D0] / 10;
            D[D0] %= 10;
            D0++;
        }
    i64 i, j, k, L;
    fortodo(i, 0, 42)
        Possi[0][i] = (c[i] == "nil") ? -1 : i;
    fortodo(i, 43, 49) Possi[0][i] = -1;
    fortodo(i, 1, D0)
        fortodo(j, 0, 49)
            {
                L = max(j - 4, 0ll);
                Possi[i][j] = -1;
                fortodo(k, L, j)
                    if ((Possi[i - 1][(j - k) * 10 + D[i - 1]] != -1) && ((k <= 42) && (c[k] != "nil")))
                        {
                            Possi[i][j] = k;
                            break;
                        }
            }
    if (Possi[D0][D[D0]] == -1)
        {
            printf("-1\n");
            return false;
        }
    i64 answers[6];
    fortodo(i, 0, 5) answers[i] = 0;
    j = D[D0];
    for (i = D0; i >= 0; i--)
        {
            fortodo(k, 0, 5)
                answers[k] = answers[k] * 10 + c[Possi[i][j]][k] - '0';
            if (i) j = (j - Possi[i][j]) * 10 + D[i - 1];
        }
    fortodo(i, 0, 5)
        {
            cout << answers[i];
            if (i == 5)
                putchar('\n');
            else
                putchar(' ');
        }
    return true;
}

int main()
{
    int T;
    for (scanf("%d", &T); T; T--) mainprocess();
}