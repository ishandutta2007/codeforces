#include <iostream>
#include <map>
#include <set>
using namespace std;

int a[5002], n, ans;
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        mp[a[i]] ++;
        ans = max(ans, mp[a[i]]);
    }
    printf("%d\n", ans);
}