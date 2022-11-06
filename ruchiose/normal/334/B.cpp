#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int i, j, Q[8][2];

bool CHK()
{
    if (Q[0][0] != Q[1][0]) return false;
    if (Q[1][0] != Q[2][0]) return false;
    if (Q[2][0] == Q[3][0]) return false;
    if (Q[3][0] != Q[4][0]) return false;
    if (Q[4][0] == Q[5][0]) return false;
    if (Q[5][0] != Q[6][0]) return false;
    if (Q[6][0] != Q[7][0]) return false;
    if (Q[0][1] != Q[3][1]) return false;
    if (Q[3][1] != Q[5][1]) return false;
    if (Q[5][1] == Q[1][1]) return false;
    if (Q[1][1] != Q[6][1]) return false;
    if (Q[6][1] == Q[2][1]) return false;
    if (Q[2][1] != Q[4][1]) return false;
    if (Q[4][1] != Q[7][1]) return false;
    return true;
};

int main()
{
    fortodo(i, 0, 7)
        fortodo(j, 0, 1)
            scanf("%d", &Q[i][j]);
    fortodo(i, 0, 6)
        fortodo(j, i + 1, 7)
            {
                if (Q[i][0] > Q[j][0])
                    {
                        swap(Q[i][0], Q[j][0]);
                        swap(Q[i][1], Q[j][1]);
                    };
                if (Q[i][0] != Q[j][0]) continue;
                if (Q[i][1] > Q[j][1])
                    {
                        swap(Q[i][0], Q[j][0]);
                        swap(Q[i][1], Q[j][1]);
                    };
                if (Q[i][1] != Q[j][1]) continue;
            };
    printf("%s\n", (CHK()) ? "respectable" : "ugly");
    return 0;
};