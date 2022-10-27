#include <iostream>
#include <map>
using namespace std;
int n; char s[100000+10];
map<int, int> mp;
int main() {
    scanf("%d %s", &n, s + 1);
    
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == '1') {
            mp[++ sum] = i;
        } else {
            mp[-- sum] = i;
        }
    }

    sum = 0; int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = max(ans, mp[sum] - i + 1);
        if (s[i] == '1') sum ++;
        else sum --;
    }

    printf("%d\n", ans);
}