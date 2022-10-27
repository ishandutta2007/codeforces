#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,a[N];
set<int> st;
int main() {
    scanf("%d",&n);
    int ans=-1;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]>st.size()) {
            ans = i; break;
        }
        st.insert(a[i]);
    }
    cout<<ans<<endl;
}