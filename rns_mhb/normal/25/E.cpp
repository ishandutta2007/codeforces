/// CF 25 E

#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back

#define inf 1e9
#define INF 1e18

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

#define N 100010

int p[3][N], len[3], f[3][3];
bool c[3][3];
char s[3][N];

void prepare(int x) {
    p[x][1] = 0;
    for(int i = 2, k = 0; i <= len[x]; i ++) {
        while(k && s[x][k + 1] != s[x][i]) k = p[x][k];
        if(s[x][k + 1] == s[x][i]) k ++;
        p[x][i] = k;
    }
}

bool func(int x, int y) {
    for(int i = 1, k = 0; i <= len[y]; i ++) {
        while(k && s[x][k + 1] != s[y][i]) k = p[x][k];
        if(s[x][k + 1] == s[y][i]) k ++;
        if(k == len[x]) return 1;
        if(i == len[y]) f[y][x] = k;
    }
    return 0;
}

int main() {
    int mx = 0, i, j;
    scanf("%s%s%s", s[0] + 1, s[1] + 1, s[2] + 1);
    for(i = 0; i < 3; i ++) {
        len[i] = strlen(s[i] + 1);
        prepare(i);
    }
    for(i = 0; i < 3; i ++) for(j = 0; j < 3; j ++) if(i != j) c[i][j] = func(i, j);
    if(c[0][1] || c[0][2]) {
        if(c[1][2]) {printf("%d\n", len[2]);return 0;}
        if(c[2][1]) {printf("%d\n", len[1]);return 0;}
        printf("%d\n", len[1] + len[2] - max(f[1][2], f[2][1]));
        return 0;
    }
    if(c[1][0] || c[1][2]) {
        if(c[0][2]) {printf("%d\n", len[2]);return 0;}
        if(c[2][0]) {printf("%d\n", len[0]);return 0;}
        printf("%d\n", len[0] + len[2] - max(f[0][2], f[2][0]));
        return 0;
    }
    if(c[2][1] || c[2][0]) {
        if(c[0][1]) {printf("%d\n", len[1]);return 0;}
        if(c[1][0]) {printf("%d\n", len[0]);return 0;}
        printf("%d\n", len[0] + len[1] - max(f[0][1], f[1][0]));
        return 0;
    }
    chkmax(mx, f[0][1] + f[1][2]);
    chkmax(mx, f[2][1] + f[1][0]);
    chkmax(mx, f[1][0] + f[0][2]);
    chkmax(mx, f[2][0] + f[0][1]);
    chkmax(mx, f[1][2] + f[2][0]);
    chkmax(mx, f[0][2] + f[2][1]);
    printf("%d\n", len[0] + len[1] + len[2] - mx);
}