#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
multiset<int> st1,st2;
int n;
int main() {
    scanf("%d",&n);
    st1.insert(0); st2.insert(0);
    for(int i=1;i<=n;i++) {
        int x; scanf("%d", &x); st1.insert(x);
    }
    for(int i=1;i<=n;i++) {
        int x; scanf("%d", &x); st2.insert(x);
    }
    LL ans = 0;
    for(int i=1;i<=n;i++) {
        if (*st1.rbegin() >= *st2.rbegin()) {
            ans += *st1.rbegin(); st1.erase(st1.find(*st1.rbegin()));
        } else {
            st2.erase(st2.find(*st2.rbegin()));
        }
        //printf("%d\n", ans);
        if (*st2.rbegin() >= *st1.rbegin()) {
            ans -= *st2.rbegin(); st2.erase(st2.find(*st2.rbegin()));
        } else {
            st1.erase(st1.find(*st1.rbegin()));
        }
        //printf("%d\n", ans);
    }    
    cout << ans << endl;
}