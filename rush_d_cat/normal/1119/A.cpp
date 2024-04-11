#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N = 300000+10;
int n,a[N];
int mx[N],mn[N];
multiset<int> st;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    
    for(int i=1;i<=n;i++){
        if(mn[a[i]] == 0) {
            mn[a[i]]=i; st.insert(i);
        }
    }
    for(int i=n;i>=1;i--){
        if(mx[a[i]] == 0) {
            mx[a[i]]=i;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(mx[i]) {
            st.erase(st.find(mn[i]));
            ans=max(ans, mx[i] - (*st.begin()));
            st.insert(mn[i]);
        }
    }
    cout<<ans<<endl;
}