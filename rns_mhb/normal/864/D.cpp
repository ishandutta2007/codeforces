#include<bits/stdc++.h>
using namespace std;

#define N 200001

int a[N], b[N], c[N] = {};
queue <int> q[N];

int main()
{
    int n, i, num = 0, j, p;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        q[a[i]].push(i);
    }
    p = 0;
    for(i = 1; i <= n; i ++) {
        if(!q[i].empty()) {
            j = q[i].front();
            b[j] = i;
            c[j] = 1;
            continue;
        }
        else {
            for(j = p + 1; j <= n; j ++) {
                if(q[a[j]].size() > 1 && c[j] == 0) {
                    c[j] = 1;
                    b[j] = i;
                    q[a[j]].pop();
                    num ++;
                    p = j;
                    break;
                }
            }
        }
    }
    printf("%d\n", num);
    for(i = 1; i <= n; i ++) printf("%d ", b[i]);
    printf("\n");
}