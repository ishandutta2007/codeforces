#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n,q;

int main() {
    scanf("%d", &q);
    while(q--) {
        scanf("%d",&n);
        multiset<int> st;
        for(int i=1;i<=n;i++) {
            int x; scanf("%d",&x); st.insert(x);
        }
        bool ok = 0;
        while(1) {
            if (st.size() == 0) break;
            int x = *st.begin(); st.erase(st.begin());
            if (x == 2048) ok = 1;
            
            if (st.size() == 0) break;
            int y = *st.begin(); 
            if (x == y) {
                st.erase(st.begin()); st.insert(2*x);
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
}