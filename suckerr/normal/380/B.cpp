#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111111;
int left[N], right[N];
int n, m;
int tot = 0;
vector<pair<int, pair<int, int> > > sec;
int hash[N], dep[N], num = 0;

int main() {
    scanf("%d %d", &n, &m);
    tot = 1;    
    for(int i = 2; i <= n; i++) {
        int add = 0;
        for(int j = 1; j <= tot; j *= 2)
            add++;
        tot += add;
    }
    
    for(int i = 1; i <= tot; i++) {
        int add = 0, flag = 0;
        for(int j = 1; j <= i; j *= 2) {
            if (j == i) {
                left[i] = i + add;
                right[i] = i + add + 1;
                flag = 1;
                break;
            } else {
                add++;
            }
        }
        if (!flag) {
            left[i] = right[i] = i + add;
        }
    }
    
    /*
    for(int i = 1; i <= tot; i++) {
        printf("%d %d\n", left[i], right[i]);
    }*/
    
    for(int i = 1; i <= m; i++) {
        int type, level, l, r, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d %d", &level, &l, &r, &x);
            dep[num++] = level;
            for(int j = level + 1; j <= n; j++) {
                l = left[l];
                r = right[r];
            }
            sec.push_back(make_pair(x, make_pair(l, r)));
        } else {
            scanf("%d %d", &level, &x);
            l = r = x;
            for(int j = level + 1; j <= n; j++) {
                l = left[l];
                r = right[r];
            }
            int ans = 0;
            for(int j = 0; j < (int)sec.size(); j++) {
                if (dep[j] >= level && sec[j].second.first <= r && sec[j].second.second >= l) {
                    if (!hash[sec[j].first])
                        ans++;
                    hash[sec[j].first] = 1;
                }
            }
            for(int j = 0; j < (int)sec.size(); j++) {
                hash[sec[j].first] = 0;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}