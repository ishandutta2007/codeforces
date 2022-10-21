#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;

int n, m;
string mp[N];
bool on[N][N];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
bool vis[N][N];

void No() {
    cout << "NO" << endl;
    exit(0);

}

bool in_bound(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> mp[i];
        mp[i] = " " + mp[i];
        for(int j = 1; j <= m; j++) on[i][j] = (mp[i][j] == '*');
    }
    int mxi = -1, mxval = 0;
    for(int i = 2; i <= n - 1; i++) {
        int cnt = 0;
        for(int j = 1; j <= m; j++) cnt += on[i][j];
        if(cnt > mxval) mxval = cnt, mxi = i;
    }
    if(mxval == 0) return cout << "NO" << endl, 0;
    int mxj = -1; mxval = 0;
    for(int j = 2; j <= m - 1; j++) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += on[i][j];
        if(cnt > mxval) mxval = cnt, mxj = j;
    }
    
    if(!on[mxi][mxj]) No();
    vis[mxi][mxj] = true;
    for(int d = 0; d < 4; d++) {
        bool in = true;
        int ci = mxi + dx[d], cj = mxj + dy[d];
        if(!on[ci][cj]) return cout << "No" << endl, 0;

        while(in_bound(ci, cj)) {

            if(in) {
                if(!on[ci][cj]) in = false;
            }
            else {
                if(on[ci][cj]) return cout << "NO" << endl, 0;
            }
            if(on[ci][cj]) vis[ci][cj] = true;
            ci += dx[d], cj += dy[d];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(on[i][j] && !vis[i][j]) return cout << "NO" << endl, 0;
        }
    }

    cout << "YES" << endl;

}