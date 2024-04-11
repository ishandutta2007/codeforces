#include <bits/stdc++.h>

using namespace std;

int a[10][10][10];

void fila (int i, int j, int k, int w) {
    if (a[i][j][k] != -1 && a[i][j][k] <= w)
        return;
    a[i][j][k] = w;
    fila(i, j, (k+i)%10, w+1);
    fila(i, j, (k+j)%10, w+1);
}

int main()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                a[i][j][k] = -1;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            fila(i, j, i, 0);
            fila(i, j, j, 0);
        }
    int ans[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            ans[i][j] = 0;
    string s;
    cin >> s;
    int del;
    for (int q = 1; q < s.length(); q++) {
        if (s[q] >= s[q-1])
            del = s[q] - s[q-1];
        else
            del = 10 + s[q] - s[q-1];
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                if (ans[i][j] == -1)
                    continue;
                if (a[i][j][del] == -1) {
                    ans[i][j] = -1;
                    continue;
                }
                ans[i][j] += a[i][j][del];
            }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}