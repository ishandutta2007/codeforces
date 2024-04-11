#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100000+10;
LL n,m;
LL a[N],b[N];
int main() {
    scanf("%lld%lld",&n,&m);
    LL sum = 0;
    vector<LL> vec;
    for(int i=1;i<=n;i++) scanf("%lld %lld",&a[i],&b[i]), sum += a[i], vec.push_back(a[i] - b[i]);
    sort(vec.begin(), vec.end());
    sum -= m;
    LL x = 0, ans = 0;
    //printf("sum = %lld\n", sum);
    for(int i=(int)vec.size()-1;i>=0;i--) {
        if (x >= sum) break;
        x += vec[i];
        ans ++;
    }
    if (x < sum) ans = -1;
    printf("%lld\n", ans);
}