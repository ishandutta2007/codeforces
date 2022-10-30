#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
#define N 1010
bitset<N> s[N], tmp, rlt, rlt1, S[N];
int sz[N];
bool vis[N][N];
pi A[N * N];
vector<int> v[N];
int a[N], di[N], pa[N];

int Mx(bitset<N> tmp) {
    int rlt = 0;
    for(int i = 9; i >= 0; i --) {
        if((tmp >> (rlt + (1 << i))).count()) rlt += 1 << i;
    }
    return rlt;
}

int main() {
    int n;
    //freopen("1.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &sz[i]);
        for(int j = 0; j < sz[i]; j ++) {
            int x;
            scanf("%d", &x);
            s[i][x - 1] = 1;
        }
    }
    for(int i = 0; i < n; i ++) for(int j = i + 1; j < n; j ++) {
        tmp = s[i] & s[j];
        if(tmp.count() != 2) continue;
        int x = Mx(tmp);
        tmp[x] = 0;
        int y = Mx(tmp);
        vis[x][y] = vis[y][x] = 1;
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++) for(int j = i + 1; j < n; j ++) if(vis[i][j]){
        v[i].push_back(j);
        v[j].push_back(i);
        A[cnt ++] = pi(i, j);
    }
    if(!cnt) {
        for(int i = 2; i <= n; i ++) printf("1 %d\n", i);
        return 0;
    }
    if(cnt == 1) {
        tmp = 0;
        int x = A[0].first;
        int y = A[0].second;
        bool bf = 0;
        for(int i = 0; i < n; i ++) {
            if(sz[i] == n) continue;
            if(!bf) {
                bf = 1;
                for(int j = 0; j < n; j ++) if(s[i][j] && j != x) {
                    printf("%d %d\n", x + 1, j + 1);
                }
                tmp = s[i];
            } else if(tmp != s[i]) {
                for(int j = 0; j < n; j ++) if(s[i][j] && j != x && j != y) {
                    printf("%d %d\n", y + 1, j + 1);
                }
                return 0;
            }
        }
    }
    int st = 0;
    int en = 0;
    for(int i = 0; i < n; i ++) if(v[i].size() >= 2){
        a[en ++] = i;
        di[i] = 0;
        pa[i] = -1;
        while(en - st > 0) {
            int x = a[st];
            if(di[x] == v[x].size()) st ++;
            else if(v[x][di[x]] == pa[x]) di[x] ++;
            else {
                int y = v[x][di[x]];
                pa[y] = x;
                di[y] = 0;
                di[x] ++;
                a[en ++] = y;
            }
        }
        break;
    }
    for(int i = 0; i < n; i ++) rlt1[i] = 1;
    for(int i = 0; i < n; i ++) if(v[i].size()) {
        S[i][i] = 1;
        for(int j = 0; j < v[i].size(); j ++) S[i][v[i][j]] = 1;
        rlt[i] = 1;
        rlt1[i] = 0;
    }
    for(int i = en - 1; i >= 0; i --) {
        int k = a[i];
        for(int j = 0; j < n; j ++) {
            tmp = s[j] & rlt;
            if(tmp != S[k]) continue;
            tmp = s[j] & rlt1;
            while(1) {
                int x = Mx(tmp);
                if(!v[x].size()) {
                    v[k].push_back(x);
                    v[x].push_back(k);
                }
                tmp[x] = 0;
                if(!tmp.count()) break;
            }
            break;
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < v[i].size(); j ++) {
            int k = v[i][j];
            if(k > i) printf("%d %d\n", i + 1, k + 1);
        }
    }
    return 0;
}