#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

char s[sz][sz];
int gone[sz][sz];

int n, m, t;

typedef pair <int, int> pii;
#define x first
#define y second

deque <pii> q;

bool notin(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m) return 1;
    return 0;
}

bool fnc(int x, int y, char c)
{
    if(notin(x, y)) return 0;
    return s[x][y] == c;
}

void dofor(int nx, int ny, int x, int y)
{
    if(notin(nx, ny)) return;

    int w = 1;
    if(s[nx][ny] == s[x][y]) w = 0;

    if(!gone[nx][ny] || gone[nx][ny] > w + gone[x][y]) {
        gone[nx][ny] = w + gone[x][y];
        if(w) q.push_back({nx, ny});
        else q.push_front({nx, ny});
    }
}

int main()
{
    cin >> n >> m >> t;
    for(int i=0; i<n; i++) scanf("%s", s[i]);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(fnc(i-1, j, s[i][j])) gone[i][j] = 1;
            if(fnc(i+1, j, s[i][j])) gone[i][j] = 1;
            if(fnc(i, j+1, s[i][j])) gone[i][j] = 1;
            if(fnc(i, j-1, s[i][j])) gone[i][j] = 1;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(gone[i][j]) {
                q.push_back({i, j});
            }
        }
    }

    while(!q.empty()) {
        pii p = q.front();
        q.pop_front();

        int x = p.x, y = p.y;
        dofor(x-1, y, x, y);
        dofor(x+1, y, x, y);
        dofor(x, y-1, x, y);
        dofor(x, y+1, x, y);
    }

    while(t--) {
        int x, y;
        ll p;
        scanf("%d %d %lld", &x, &y, &p);
        x--, y--;

        if(p < gone[x][y] || !gone[x][y]) printf("%c\n", s[x][y]);
        else {
            ll z = p - gone[x][y];
            if(z & 1) printf("%c\n", s[x][y]);
            else printf("%c\n", s[x][y] == '1' ? '0' : '1');
        }
    }
}