#include <bits/stdc++.h>
using namespace std;

const int N = 260, MK = (1 << 8) - 1;
typedef pair<int, int> P;
typedef pair<int, string> Ps;
typedef pair<Ps, P> Pp;


int dis[N][3];
string best[N][3];

int to_int(string str) {
    int res = 0;
    for(int i = 0; i < 8; i++) res = (res * 2 + (str[i] - '0'));
    return res;
}

priority_queue<Pp, vector<Pp>, greater<> > pque;


void upd(int len, string str, int i, int j) {
    if(len < dis[i][j] ||
        (len == dis[i][j] && str < best[i][j])) {
        dis[i][j] = len;
        best[i][j] = str;
        pque.push({{len, str}, {i, j}});
    }
}

int main() {
    memset(dis, 0x3f, sizeof(dis));
    int x = to_int("00001111"), y = to_int("00110011"), z = to_int("01010101");
    dis[x][0] = dis[y][0] = dis[z][0] = 1;
    best[x][0] = "x", best[y][0] = "y", best[z][0] = "z";
    pque.push({{1, "x"}, {x, 0}});
    pque.push({{1, "y"}, {y, 0}});
    pque.push({{1, "z"}, {z, 0}});
    while(!pque.empty()) {
        Pp pp = pque.top(); pque.pop();
        int len = pp.first.first;
        string str = pp.first.second;
        x = pp.second.first;
        int j = pp.second.second;

        if(len > dis[x][j] || str > best[x][j]) continue;
        if(j == 0) {
            upd(len, str, x, 1);
            upd(1 + len, "!" + str, MK - x, 0);
            for(int i = 0; i <= MK; i++) {
                upd(dis[i][1] + 1 + len, best[i][1] + "&" + str, x & i, 1);
            }
        }
        else if(j == 1) {
            upd(len, str, x, 2);
            for(int i = 0; i <= MK; i++) {
                upd(len + 1 + dis[i][0], str + "&" + best[i][0], x & i, 1);
                upd(dis[i][2] + 1 + len, best[i][2] + "|" + str, x | i, 2);
            }
        }
        else {
            upd(len + 2, "(" + str + ")", x, 0);
            for(int i = 0; i <= MK; i++) {
                upd(len + 1 + dis[i][1], str + "|" + best[i][1], x | i, 2);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        cout << best[to_int(s)][2] << "\n";
    }


}