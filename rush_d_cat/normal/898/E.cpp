#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 200000+10;

map<LL, int> mp;

int n; 
LL a[N], sqr[N];

void init() {
    for (LL i = 0; i < N; i ++) {
        sqr[i] = i * i;
        mp[i * i] = 1;
    }
}

int main() {
    init();
    scanf("%d", &n);
    int cnt = 0; // is_sqr
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        if(mp[a[i]]) cnt ++;
    }

    LL ans = 0;
    vector<LL> vec;

    if (cnt < n / 2) {
        for (int i = 1; i <= n; i ++) if (mp[a[i]] == 0) {
            LL v1 = sqr[lower_bound(sqr, sqr+N, a[i]) - sqr];
            LL v2 = sqr[lower_bound(sqr, sqr+N, a[i]) - 1 - sqr]; 
            vec.push_back(min(v1-a[i], a[i]-v2));
        }
    } else {
        for (int i = 1; i <= n; i ++) if (mp[a[i]] == 1) {
            if (a[i] == 0) vec.push_back(2);
            else vec.push_back(1);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < abs(cnt - n / 2); i ++) {
        ans += vec[i];
    }
    printf("%lld\n", ans);

}