#include <bits/stdc++.h>
using namespace std;

const int M = 200001;
int a[M], b[M], c[M];
map<int, int> mp;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), mp[a[i]] ++;
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]);
    for(int i = 1; i <= m; i ++) scanf("%d", &c[i]);
    int val1 = -1, val2 = -1, id = -1;
    for(int i = 1; i <= m; i ++) {
        int x = mp[b[i]], y = mp[c[i]];
        if(x > val1) {
            id = i;
            val1 = x;
            val2 = y;
        }
        else if(x == val1 && y > val2) {
            val2 = y;
            id = i;
        }
    }
    printf("%d\n", id);
}