#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, m[N], p[N], need[N], s[N];
vector<int> vec[N];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&m[i],&p[i]); 
            vec[m[i]].push_back(p[i]);
        }
        for(int i=0;i<n;i++) {
            s[i] = (i>=1?s[i-1]:0) + vec[i].size();
        }
        for(int i=1;i<n;i++) {
            need[i] = max(i - s[i-1], 0);
            //printf("need[%d] = %d\n", i, need[i]);
        }
        int done = 0;
        multiset<LL> st; LL ans=0;
        for(int i=n-1;i>=0;i--) {
            for (auto x: vec[i]) {
                st.insert(x);
            }
            while(done < need[i]) {
                ans += *st.begin();
                st.erase(st.begin());
                done ++; 
            }
        }
        for(int i=0;i<=n;i++) vec[i].clear();
        printf("%lld\n", ans);
    }
}