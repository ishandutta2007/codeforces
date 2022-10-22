#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int W, H, P;
int M[1010][1010];
bool visit[10][1010][1010];
int S[10], ans[10];

struct Queue{
    int x, y, t, d, p;
    bool operator<(const Queue &r)const{
        if (t == r.t && p == r.p) return d > r.d;
        if (t == r.t) return p > r.p;
        return t > r.t;
    }
};

priority_queue<Queue> Q;

void enque(int x, int y, int p, int d, int t){
    if (x < 1 || W < x || y < 1 || H < y) return;
    if (visit[p][x][y]) return;
    if (M[x][y]) return;
    visit[p][x][y] = true;
    if (d > S[p]) d=1, t++;
    Q.push({x, y, t, d, p});
}

int main(){
    char ch;
    scanf("%d %d %d", &W, &H, &P);
    for (int i=1; i<=P; i++) scanf("%d", &S[i]);
    for (int i=1; i<=W; i++){
        for (int j=1; j<=H; j++){
            scanf(" %c", &ch);
            if (ch == '.') continue;
            if (ch == '#') M[i][j] = -1;
            else Q.push({i, j, 0, S[ch-'0'], ch-'0'});
        }
    }
    while(!Q.empty()){
        Queue T = Q.top();
        Q.pop();
        if (M[T.x][T.y]) continue;
        M[T.x][T.y] = T.p;
        for (int i=0; i<4; i++) enque(T.x+dx[i], T.y+dy[i], T.p, T.d+1, T.t);
    }
    for (int i=1; i<=W; i++) for (int j=1; j<=H; j++){
        if (M[i][j] == -1) continue;
        ans[M[i][j]]++;
    }
    for (int i=1; i<=P; i++) printf("%d ", ans[i]);
    return 0;
}