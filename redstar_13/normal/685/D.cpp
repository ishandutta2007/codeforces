#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
typedef vector<int> VI;

map<int, int> s, s1;
#define NN 101010

pi3 p[NN<<1];
INT ans[NN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int n, k, u, v;
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf("%d%d", &u, &v);
        p[i<<1]=make_pair(make_pair(u, 1), v);
        p[(i<<1)|1]=make_pair(make_pair(u+k, -1), v);
    }
    
    n<<=1;
    sort(p, p+n);
    int pre=0;
    for (int i=0, j; i<n; i=j) {
        int t=p[i].first.first;
        for (j=i; j<n && p[j].first.first==t; j++) {
            if (p[j].first.second==1) {
                s[p[j].second]++;
                s[p[j].second+k]--;
                if (s[p[j].second]==0) s.erase(p[j].second);
                if (s[p[j].second+k]==0) s.erase(p[j].second+k);
            } else {
                s[p[j].second]--;
                s[p[j].second+k]++;
                if (s[p[j].second]==0) s.erase(p[j].second);
                if (s[p[j].second+k]==0) s.erase(p[j].second+k);
            }
        }
        if (j==n) break;
        int cur=0, f=0, cur1, pre1;
        int x=p[j].first.first-p[i].first.first;
        for (auto it : s) {
            cur+=it.second;
            if (f) {
                ans[cur1]+=(INT)x*(it.first-pre1);
            }
            f=1;
            pre1=it.first;
            cur1=cur;
        }
    }
    for (int i=1; i<=n>>1; i++) printf("%I64d ", ans[i]);puts("");

    return 0;
}