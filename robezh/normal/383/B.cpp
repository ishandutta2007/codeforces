#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9 + 50;

struct P {
    int x, y;
};

int n, m;
P p[N];
map<int, int> mp;

bool cmp(const P& p1, const P& p2) {
    return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
}

void split(int x) {
    auto it = mp.lower_bound(x);
    if(it != mp.end() && it->second <= x) {
        if(it->second < x) mp[x-1] = it->second;

        if(it->first > x) mp[it->first] = x + 1;
        else mp.erase(it);
    }
}

void print_out() {
    cout << "map: " << endl;
    for(const auto &p : mp) {
        printf("(%d, %d)\n", p.second, p.first);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> p[i].x >> p[i].y;
    sort(p, p + m, cmp);
    int r = 0;
    int la = 0;

    mp[1] = 1;
    for(int i = 0; i < m; i = r) {
        while(r < m && p[r].x == p[i].x) r++;
        if(p[i].x > la + 1) {
            int lb = (mp.empty() ? 1 : mp.begin()->second);
            mp.clear();
            mp[n] = lb;
        }
        for(int j = i; j < r; j++) {
            split(p[j].y);
        }
        for(int j = i - 1; j < r; j++) {
            int lb = (j >= i? p[j].y + 1 : 1);
            int rb = (j + 1 < r ? p[j+1].y - 1 : n);
            int nl = INF;
            for(auto it = mp.lower_bound(lb); it != mp.end() && it -> first <= rb ; it = mp.erase(it)) {
                nl = min(nl, it->second);
            }
            if(nl != INF) {
                mp[rb] = nl;
            }
        }
        la = p[i].x;
//        print_out();
        if(mp.empty()) return !printf("-1\n");
    }

    if(p[m-1].x != n || (--mp.end())->first == n) return !printf("%d\n", 2 * n - 2);
    return !printf("-1\n");
}