#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int N = 200000 + 10;
int T,n,a[N],p[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]); p[a[i]]=i;
    }
    set<int> st; st.insert(p[n]);
    for(int i=n-1;i>=1;i--){
        if(st.count(p[i]+1) || st.count(p[i]-1)) {
            st.insert(p[i]);
        } else {
            return !printf("NO\n");
        }
    }
    printf("YES\n");
}