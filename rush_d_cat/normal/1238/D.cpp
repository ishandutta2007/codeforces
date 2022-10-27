#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300000 + 10;
typedef long long LL;
int n; char s[N];


int main() {
    scanf("%d%s",&n,s+1);
    LL ans = 0;
    vector<int> v;
    for (int i = 1, j = 1; i <= n; i = j) {
        while (j <= n && s[j] == s[i]) j ++;
        v.push_back(j - i);
    }   
    for (int i = 0; i < v.size(); i ++) {
        // printf("%d\n", v[i]);
        if (i) ans += v[i-1];
        if (i < (int)v.size() - 1) ans += v[i+1];
    }
    ans -= (v.size() - 1);
    ans = 1LL * (n) * (n - 1) / 2 - ans;
    cout << ans << endl;
}