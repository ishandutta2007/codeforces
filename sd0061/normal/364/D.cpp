#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 1000005;

int n , m;
long long a[N];

int main() {
    srand(time(0));
    scanf("%d" , &n);
    m = (n + 1) / 2;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%lld" , &a[i]);
    }
    LL res = 0;
    int T = 10;
    while (1) {
        if (1.0 * clock() / CLOCKS_PER_SEC >= 3.3)
            break;
        int x = (rand() << 15 | rand()) % n;
        map<LL , int> cnt;
        for (int j = 0 ; j < n ; ++ j)
            cnt[__gcd(a[j] , a[x])] ++;
        vector< pair<LL , int> > V;
        for (auto &it : cnt) {
            V.push_back(it);                
        }
        for (int i = 0 ; i < V.size() ; ++ i) {
            if (V[i].first > res) {
                int sum = 0;
                for (int j = i ; j < V.size() && sum < m ; ++ j) {
                    if (V[j].first % V[i].first == 0) {
                        sum += V[j].second;
                    }
                }
                if (sum >= m) {
                    res = max(res , V[i].first);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}