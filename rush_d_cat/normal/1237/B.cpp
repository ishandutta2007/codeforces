#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n, a[N], b[N], p[N];
set<int> s1;
set< pair<int,int> > s2;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &b[i]);
        p[b[i]] = i;
        //s1.insert(i);
        s2.insert(make_pair(i, b[i]));
    }
    for (int i = 1; i <= n; i ++) {
        int pos = p[a[i]];
        //printf("who = %d, pos = %d\n", a[i], p[a[i]]);
        vector< pair<int,int> > d;
        for (auto p: s2) {
            //printf("ok\n");
            if (p.first < pos) {
                //printf("del %d %d\n",p.first,p.second);
                s1.insert(p.second); d.push_back(p);
            } else {
                break;
            }
        }
        //printf("out\n");
        for (auto p: d) s2.erase(p);

        s2.erase(make_pair(pos, a[i]));
    }
    printf("%d\n", (int)s1.size());
}