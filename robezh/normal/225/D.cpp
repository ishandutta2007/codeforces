#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
#define id(i, j) (i*m+j)

const int N = 16, K = 225;

struct HASH{
    size_t operator()(const P &x)const{
        return hash<ll>()((x.first)^((x.second)<<32));
    }
};

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int n, m;
int len = 0;
ll pw[N];
string str[N];
map<P, int> dis;

bool good(P p, int i, int j) {
    int cur = id(i, j);
    for(int k = 0; k < len - 1 - 5; k++) if(p.first / pw[k] % K == cur) return false;
    for(int k = 0; k < min(len - 1, 5); k++) if(p.second / pw[k] % K == cur) return false;
    return true;
}

bool in_bound(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && str[i][j] != '#';
}


P getnxt(P p, int i, int j) {
    p.first *= K;
    p.first += p.second / pw[4];
    p.first %= pw[max(len - 5, 0)];
    p.second *= K;
    p.second += id(i, j);
    p.second %= pw[min(len, 5)];
    return p;
}



int main() {
    pw[0] = 1;
    for(int i = 1; i < 6; i++) pw[i] = pw[i-1] * K;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> str[i];

    P ori;
    queue<P> que;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c = str[i][j];
            if(c >= '1' && c <= '9') {
                int x = c - '0';
                len = max(len, x);
                x--;
                if(x >= 5) ori.first += id(i, j) * pw[x - 5];
                else ori.second += id(i, j) * pw[x];
            }
        }
    }
    que.push(ori);
    dis[ori] = 0;
    while(!que.empty()) {
        P p = que.front(); que.pop();
        int curdis = dis[p];
        int ci = (int)(p.second % K / m), cj = (int)(p.second % K % m);
        for(int d = 0; d < 4; d++) {
            int ni = ci + dx[d], nj = cj + dy[d];
            if(in_bound(ni, nj) && good(p, ni, nj)) {
                if(str[ni][nj] == '@') {

                    return cout << curdis + 1 << endl, 0;
                }
                P nxt = getnxt(p, ni, nj);
                if(!dis.count(nxt)) {
                    que.push(nxt);
                    dis[nxt] = curdis + 1;
                }
            }
        }
    }
    cout << "-1" << endl;
}