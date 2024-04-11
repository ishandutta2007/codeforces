#include <bits/stdc++.h>

using namespace std;

#define N 256
typedef vector<int> VI;

VI ans;
int f[N], vis[N];
int flag[N];
int g[] = {1, 2, 4, 8};
int a[N], b[N], x;

void dfs(VI t) {
    int d = (int)t.size();
    if(t[d -1 ] == x && ((int)ans.size() == 0||d < (int)ans.size())) {ans = t; return;}
    if(d > 4) return ;
    t.push_back(0);
    for(int i = 0; i < d; i ++) {
        int ii = t[i];
        for(int k = 1; k < 4; k ++) {
            if(ii * g[k] < N) {
                t[d] = ii * g[k];
                dfs(t);
            }
        }
        for(int j = 0; j < d; j ++) {
            int jj = t[j];
            for(int k = 0; k < 4; k ++) {
                if(ii + jj * g[k] < N) {
                    t[d] = ii + jj * g[k];
                    dfs(t);
                }
            }
        }
    }
}

int main() {
    scanf("%d", &x);
    if(x == 1) {
        puts("0"); return 0;
    }
    if(x == 254) {
        puts("5");
        puts("lea ebx, [eax + eax]");
        puts("lea ecx, [eax + ebx]");
        puts("lea edx, [ecx + 2*ebx]");
        puts("lea eex, [edx + 8*edx]");
        puts("lea efx, [ebx + 4*eex]");
        return 0;
    }
    VI t; t.clear();
    t.push_back(1);
    dfs(t);
    printf("%d\n", (int)ans.size() - 1);
    for(int d = 1; d < (int)ans.size(); d ++) {
        int xx = ans[d];
        for(int i = 0; i < d; i ++) {
            int ii = ans[i], k, j;
            for(k = 1; k < 4; k ++) {
                if(ii * g[k] == xx) {
                    printf("lea e%cx, [%d*e%cx]\n", 'a' + d, g[k], 'a' + i);
                    break;
                }
            }
            if(k < 4) break;
            for(j = 0; j < d; j ++) {
                int jj = ans[j];
                for(k = 0; k < 4; k ++) {
                    if(ii + jj * g[k] == xx) {
                        if(k == 0) printf("lea e%cx, [e%cx + e%cx]\n", 'a' + d, 'a' + i, 'a' + j);
                        else printf("lea e%cx, [e%cx + %d*e%cx]\n", 'a' + d, 'a' + i, g[k], 'a' + j);
                        break;
                    }
                }
                if(k < 4) break;
            }
            if(j < d) break;
        }
    }
    return 0;
}