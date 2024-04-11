#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

int n;
LL a, b;
map<LL, int> mp;

int main() {
    for(LL x = 1; x <= 1e6; x ++) {
        mp[x*x*x] = x;
    }
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld", &a, &b);
        
        if(mp[a*b] && a%mp[a*b]==0 && b%mp[a*b] == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}