#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL n, v[60000+10];
vector<int> ans;

int main() {
    cin >> n;
    LL sum = n * (n + 1) / 2; sum /= 2;
    for (int i = n; i >= 1; i --) {
        if (sum >= i) {
            sum -= i; ans.push_back(i);
        }
    }
    if ( (n * (n+1) / 2) & 1 ) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    printf("%d ", ans.size());
    for (int i = 0; i < ans.size(); i ++)
        printf("%d ", ans[i]);
}