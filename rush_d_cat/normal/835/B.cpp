#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 200000+10;
LL k;
char s[NICO];

int main() {
    cin >> k;
    scanf("%s", s+1);
    int n = strlen(s+1);
    LL sum = 0;
    for(int i=1;i<=n;i++) {
        sum += s[i] - '0';
    }
    sort(s+1, s+1+n);

    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(sum < k) ans ++;
        sum += '9' - s[i];
    }
    cout << ans << endl;
}