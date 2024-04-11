#include <iostream>
#include <set>
using namespace std;
int n,k,a[102],c[102];
set<int> st;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        st.insert(a[i]);
    }
    if (st.size() < k)
        return !printf("NO\n");
    printf("YES\n");
    st.clear();
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(st.count(a[i]) == 0) { 
            printf("%d ", i);
            cnt ++; st.insert(a[i]);
            if (cnt == k) return 0;
        }
    }
}