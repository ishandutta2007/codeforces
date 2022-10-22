#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , x;
pair<int , int> a[N];
void work() {
    int i , res = 0;
    cin >> n >> x;
    for (i = 0 ; i < n ; ++ i) {
        cin >> a[i].first >> a[i].second;
        res += a[i].second - a[i].first + 1;
    }
    sort(a , a + n);
    res += (a[0].first - 1) % x;
    for (int i = 1 ; i < n ; ++ i)
        res += (a[i].first - a[i - 1].second - 1) % x;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}