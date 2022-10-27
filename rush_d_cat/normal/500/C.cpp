#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N=1002;
int n,m;int w[N],b[N];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    LL ans = 0;
    for(int i=1;i<=m;i++){
        set<int> st;
        for(int j=i-1;j>=1;j--) {
            if(b[j]!=b[i]) st.insert(b[j]);
            else break;
        }
        for(auto x: st) ans += w[x];
    }
    cout<<ans<<endl;
}