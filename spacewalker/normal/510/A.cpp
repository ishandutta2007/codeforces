#include <bits/stdc++.h>

using namespace std;

char cRow[100];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) printf("#");
        } else {
            memset(cRow, '.', sizeof cRow);
            if ((i-1)/2 % 2 == 0) cRow[m-1] = '#';
            else cRow[0] = '#';
            for (int j = 0; j < m; ++j) printf("%c", cRow[j]);
        }
        printf("\n");
    }
}