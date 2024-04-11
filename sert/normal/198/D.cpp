#include <bits/stdc++.h>

using namespace std;

const int N = 54;
int a[N][N][N];

void go_odd(int n) {
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < n - 1; j++)
            for (int k = 0; k < n - 1; k++)
                a[i][j][k] = a[i - 1][j][k] + (n - 1) * (n - 1);
    int st = 1;
    for (int k = 0; k < n - 1; k++) {
        if (k % 2)
            for (int j = n - 2; j >= 0; j--)
                a[0][j][k] = st++;
        else
            for (int j = 0; j < n - 1; j++)
                a[0][j][k] = st++;
    }
    st += (n - 1) * (n - 1) * (n - 1);
    for (int j = 0; j < n - 1; j++) {
        if (j % 2)
            for (int i = 0; i < n; i++)
                a[i][j][n - 1] = st++;
        else
            for (int i = n - 1; i >= 0; i--)
                a[i][j][n - 1] = st++;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i % 2)
            for (int k = 1; k < n; k++)
                a[i][n - 1][k] = st++;
        else
            for (int k = n - 1; k > 0; k--)
                a[i][n - 1][k] = st++;            
    }
    for (int i = 0; i < n; i++)
        a[i][n - 1][0] = st++;
}

void go_even(int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > 0; j--)
            for (int k = n - 1; k > 0; k--)
                a[i][j][k] = a[i][j - 1][k - 1] + (n - 1) * (n - 1);
    int st = 1;

    for (int i = 0; i < n - 1; i++) {
        if (i % 2)
            for (int k = 2; k < n; k++)
                a[i][0][k] = st++;
        else
            for (int k = n - 1; k > 1; k--)
                a[i][0][k] = st++;
    }
    for (int i = n - 2; i >= 0; i--)
        a[i][0][1] = st++;

    st += (n - 1) * (n - 1) * (n - 1);

    for (int j = n - 1; j >= 0; j--) {
        if (j % 2)
            for (int i = n - 2; i >= 0; i--)
                a[i][j][0] = st++;
        else
            for (int i = 0; i < n - 1; i++)
                a[i][j][0] = st++;
    }

    for (int k = 0; k < n; k++)
        if (k % 2)
            for (int j = n - 1; j >= 0; j--)
                a[n - 1][j][k] = st++;
        else
            for (int j = 0; j < n; j++)
                a[n - 1][j][k] = st++;
}

void go(int n) {
    if (n == 1) {
        a[0][0][0] = 1;
        return;
    }
    go(n - 1);
    if (n % 2)
        go_odd(n);
    else
        go_even(n);
}

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    go(n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k < n; k++)
                printf("%d ", a[j][k][i]);
            printf("\n");
        }
        printf("\n");
    }
}