#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long LL;
using namespace std;
const int N = 100005;
int n , K;
int a[N];

void work() {
    scanf("%d%d" , &n , &K);
    vector<int> w;
    int p = 0;
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        res += a[i] / 10;
        if (a[i] % 10) {
            w.push_back(10 - a[i] % 10);
            a[i] += 10 - a[i] % 10;
        }
        p += (100 - a[i]) / 10;
    }
    sort(w.begin() , w.end() , greater<int>());
    while (!w.empty() && K >= w.back()) {
        K -= w.back();
        ++ res;
        w.pop_back();
    }
    res += min(K / 10 , p);
    cout << res << endl;
}

int main() {
    work();
    return 0;
}