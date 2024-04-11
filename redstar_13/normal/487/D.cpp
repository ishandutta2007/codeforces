#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

const int M = 323;
int n, m;
int dx[]={0, -1, 0};
int dy[]={-1, 0, 1};
int flag;
int vst[M*M][12];
pii nxt[M*M][12];
char s[M*M][12];

pii go(int u, int v, int st) {
    if (u<st || v<0 || v>=m) return make_pair(u, v);
    if (vst[u][v]==flag) return nxt[u][v];
    vst[u][v]=flag;
    int uu=u+dx[s[u][v]], vv=v+dy[s[u][v]];
    return nxt[u][v]=go(uu, vv, st);
}

void build(int k) {
    int st=k*M, ed=min(n, k*M+M);
    ++flag;
    for (int i=st; i<ed; i++) {
        for (int j=0; j<m; j++) {
            if (j && s[i][j]==0 && s[i][j-1]==2) nxt[i][j]=make_pair(-2, -2), vst[i][j]=flag;
            else if (j<m-1 && s[i][j]==2 && s[i][j+1]==0) nxt[i][j]=make_pair(-2, -2), vst[i][j]=flag;
        }
        for (int j=0; j<m; j++) if (vst[i][j]!=flag) go(i, j, st);
    }
}

#define x first
#define y second

pii get_next(int x, int y) {
    pii a = nxt[x][y];
    while (a.x>=0 && a.y>=0 && a.y<m) a=nxt[a.x][a.y];
    return a;
}

int di[222];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int q;
    cin>>n>>m>>q;
    for (int i=0; i<n; i++) cin>>s[i];
    di['<']=0; di['^']=1; di['>']=2;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) s[i][j]=di[s[i][j]];
    for (int i=0; i<M; i++) build(i);

    char c; int x, y;
    while (q--) {
        cin>>c>>x>>y;
        x--; y--;
        if (c=='C') {
            cin>>c;
            s[x][y]=di[c];
            build(x/M);
        } else {
            pii a = get_next(x, y);
            cout << a.x+1 << ' ' << a.y+1 << endl;
        }
    }

    return 0;
}