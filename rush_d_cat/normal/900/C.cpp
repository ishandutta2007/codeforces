#include <iostream>
#include <set>
using namespace std;

int n, a[100000+10], cnt[100000+10];
set<int> st;

int main() {

    st.insert(0); st.insert(-1);
    
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        
        int mx = *st.rbegin();    
        st.erase(mx);
        int nx = *st.rbegin();
        st.insert(mx);    
        
        if (a[i] > mx) cnt[a[i]] --;

        if (a[i] < mx && a[i] > nx) {
            cnt[mx] ++;
        }
        st.insert(a[i]);
    }

    int best = 1, mx = -1;
    for (int i = 1; i <= n; i++) {
        //printf("%d\n", cnt[i]);
        if (cnt[i] > mx) {
            mx = cnt[i], best = i;
        }
    }
    printf("%d\n", best);
}