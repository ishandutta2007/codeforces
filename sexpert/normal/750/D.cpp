#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

/*
    Describe according to type, using one paramenter. In order
    Vertical, with form x = c
    Antidiagonal, with form x + y = c
    Horizontal, with form y = c
    Diagonal, with form x - y = c
*/

vector<ii> dirs = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
map<ii, bool> mark;
string s = "VAHD";

void ref(char c, int param) {
    for(int i = -150; i <= 150; i++) {
        for(int j = -150; j <= 150; j++) {
            ii pos = {i, j};
            if(mark[pos]) {
                ii nxt;
                if(c == 'V')
                    nxt = {2*param - i, j};
                if(c == 'H')
                    nxt = {i, 2*param - j};
                if(c == 'A')
                    nxt = {param - j, param - i};
                if(c == 'D')
                    nxt = {param + j, i - param};
                mark[nxt] = true;
            }
        }
    }
}

int main() {
    int n, d = 0;
    cin >> n;
    ii pos = {0, -1};
    stack<ii> proc;
    stack<int> sz;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sz.push(t);
        ii dir = dirs[d];
        while(t--) {
            pos = {pos.first + dir.first, pos.second + dir.second};
            proc.push(pos);
        }
        d = (d + 1) % 8;
    }
    while(!sz.empty()) {
        int t = sz.top();
        sz.pop();
        while(t--) {
            ii cur = proc.top();
            proc.pop();
            mark[cur] = true;
        }
        if(!sz.empty()) {
            char c = s[(n + 2)%4];
            int param;
            if(c == 'H')
                param = proc.top().second;
            if(c == 'V')
                param = proc.top().first;
            if(c == 'A')
                param = proc.top().first + proc.top().second;
            if(c == 'D')
                param = proc.top().first - proc.top().second;
            ref(c, param);
            n--;
        }
    }
    int ans = 0;
    for(int i = -150; i <= 150; i++) {
        for(int j = -150; j <= 150; j++) {
            if(mark[{i, j}])
                ans++;
        }
    }
    cout << ans << endl;
}