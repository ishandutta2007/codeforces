#include<bits/stdc++.h>
using namespace std;

#define N 5010

vector <int> v[N];
int n, k, c[N];

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1, x; i <= n; i ++) {
        scanf("%d", &x);
        v[x].push_back(i);
    }
    for(int i = 0, h = 0; i < N; i ++) {
        if(v[i].size() > k) {puts("NO"); return 0;}
        for(int j = 0; j < v[i].size(); j ++, h ++) {
            if(h == k) h = 0;
            c[v[i][j]] = h;
        }
    }
    puts("YES");
    for(int i = 1; i <= n; i ++) printf("%d ", c[i]+1);
    puts("");
}