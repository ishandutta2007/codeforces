#include <bits/stdc++.h>
using namespace std;
#define M 1010

int n;
int a[M];
int b[M];
int num[M];
map<int, int> mp, mb;

int main() {
    //freopen("D2.in", "r", stdin);
    scanf("%d", &n);
    int m = n;
    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);
        mp[x]++;
    }
    n = 0;
    for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
        a[++n] = it->first;
        num[n] = it->second;
    }

    int answer = 2;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        b[0] = a[i], b[1] = a[j];
        //printf("i = %d, j = %d\n", i, j);
        mb.clear();
        if (i == j && num[i] == 1) {
            continue;
        }
        mb[b[0]]++, mb[b[1]]++;

        int c;
        for (c = 2; c < m; c++) {
            b[c] = b[c-1] + b[c-2];
            //printf("b[%d] = %d\n", c, b[c]);
            if (++mb[b[c]] > mp[b[c]]) {
                break;
            }
        }
        //printf("c = %d\n", c);
        answer = max(answer, c);
        if (c == m) {
            printf("%d\n", m);
            return 0;
        }
    }
    printf("%d\n", answer);
    return 0;
}