#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL n, k, s;

int main() {
    cin>>n>>k>>s;

    vector<LL> ans;
    LL L = k, R = k * (n-1);
    if (s < L || s > R) {
        return !printf("NO\n");
    }
    LL now = 1; ans.push_back(1);
    for(int i=1;i<=s/(n-1);i++) {
        now = n+1-now;
        ans.push_back(now); 
    }

    if (s%(n-1)) {
        if (now == 1) ans.push_back(1+s%(n-1));
        if (now == n) ans.push_back(n-s%(n-1));
    }
    k -= (ans.size()-1);
    vector<LL> ret;
    for(int i=0;i<ans.size();i++) {
        ret.push_back(ans[i]);
        LL cur = ans[i];
        while (k) {
            if (ans[i+1] > ans[i]) {
                if (cur+1 < ans[i+1]) {
                    ret.push_back(++cur); k --;
                } else {
                    break;
                }
            } else {
                if (cur-1 > ans[i+1]) {
                    ret.push_back(--cur); k --;
                } else {
                    break;
                }
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<ret.size();i++) printf("%lld ",ret[i]);
}