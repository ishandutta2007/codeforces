#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
int n;
char str[N];

vector< vector<int> > go(int st) {
    set<int> h[2] , g;
    for (int i = 0 ; i < n ; ++ i) {
        h[str[i] == 'R'].insert(i);
        g.insert(i);
    }
    vector< vector<int> > res;
    int x = st , cur = (str[x] == 'R');
    while (!g.empty()) {
        vector<int> V;
        V.push_back(x) , h[cur].erase(x) , g.erase(x);
        while (1) {
            cur ^= 1;
            auto p = h[cur].upper_bound(x);
            if (p == h[cur].end()) {
                x = *h[cur].begin();
                break;
            }
            auto it = p ++;
            int w = *(-- g.end());
            if (w == *it) {
                if (!h[cur].empty() && (h[!cur].empty() || *h[cur].begin() < *h[!cur].begin())) {
                    if (g.size() > 1) {
                        x = *h[cur].begin();
                        break;
                    }
                }
            }
            x = *it;
            h[cur].erase(x);
            g.erase(x);
            V.push_back(x);
        }
        res.push_back(V);
    }
    return res;
}

void work() {
    scanf("%s" , str);
    int cnt[2] = {} , fst[2] = {-1 , -1};
    n = strlen(str);
    for (int i = 0 ; i < n ; ++ i) {
        int type = (str[i] == 'R');
        ++ cnt[type];
        if (!~fst[type])
            fst[type] = i;
    }
    vector< vector<int> > res;
    if (n & 1) {
        if (cnt[0] > cnt[1])
            res = go(fst[0]);
        else
            res = go(fst[1]);
    } else {
        vector< vector<int> > res0 = go(fst[0]);
        vector< vector<int> > res1 = go(fst[1]);
        if (res0.size() < res1.size())
            res = res0;
        else
            res = res1;
    }
    printf("%d\n" , (int)res.size() - 1);
    for (auto &it : res)
        for (auto &x : it)
            printf("%d " , x + 1);
}

int main() {
    work();
    return 0;
}