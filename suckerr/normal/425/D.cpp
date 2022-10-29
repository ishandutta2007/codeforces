#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int N = 111111;
const int BOUND = 100000;
const double eps = 1e-8;

vector<int> pos[N];
vector<int> buck, sm;
int n, limit;
long long ans = 0;
vector<pair<pair<int, int>, int> > sec;

inline bool query(int a, const int &b, const int &c) {
    if (a > BOUND || a < 0 || pos[a].size() <= limit)
        return false;
    return *lower_bound(pos[a].begin(), pos[a].end(), b) == b
        && *lower_bound(pos[a].begin(), pos[a].end(), c) == c;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        pos[x].push_back(y);
    }   
    limit = max(10, (int)(sqrt(n) + eps) / 2);
    for(int i = 0; i <= BOUND; i++) {
        if ((int)pos[i].size() == 0)
            continue;
        sort(pos[i].begin(), pos[i].end());
        if ((int)pos[i].size() > limit) {
            buck.push_back(i);
        } else {
            sm.push_back(i);
        }
    }
    for(int i = 0; i < (int)buck.size(); i++) {
        for(int j = i + 1; j < (int)buck.size(); j++) {
            int c = buck[j] - buck[i];
            int a = buck[i], b = buck[j];
            for(int k = 0, kk = 0, p = 0, pp = 0; k < (int)pos[a].size(); k++) {
                while(pos[a][kk] + c < pos[a][k])
                    kk++;
                while(p < (int)pos[b].size() && pos[b][p] < pos[a][k])
                    p++;
                while(pos[b][pp] + c < pos[b][p])
                    pp++;
                if (p < (int)pos[b].size() && pos[a][k] == pos[b][p] && pos[a][kk] + c == pos[a][k] && pos[b][pp] + c == pos[b][p])
                    ans++;
            }
        }
    }
    for(int i = 0; i < (int)sm.size(); i++) {
        int a = sm[i];
        for(int j = 0; j < (int)pos[a].size(); j++)
            for(int k = j + 1; k < (int)pos[a].size(); k++) {
                sec.push_back(make_pair(make_pair(pos[a][j], pos[a][k]), a));
            }
    }
    sort(sec.begin(), sec.end());
    for(int i = 0, j = 0; i < (int)sec.size(); i = j) {
        for(j = i; j < (int)sec.size() && sec[i].first == sec[j].first; j++);
        int c = sec[i].first.second - sec[i].first.first;
        for(int k = i, kk = i; k < j; k++) {
            while(sec[kk].second + c < sec[k].second)
                kk++;
            if (sec[kk].second + c == sec[k].second)
                ans++;
        }
    }
    for(int i = 0; i < (int)sec.size(); i++) {
        int c = sec[i].first.second - sec[i].first.first;
        ans += query(sec[i].second - c, sec[i].first.first, sec[i].first.second);
        ans += query(sec[i].second + c, sec[i].first.first, sec[i].first.second);
    }
    printf("%I64d\n", ans);
    return 0;
}