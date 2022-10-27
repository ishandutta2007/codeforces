#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vector<int> ans;
    for(int T=1;T<=n;T++) {
        bool ok=1;
        for(int i=0;i<n;i++){
            if(a[i]-a[i+1] != a[i%T]-a[i%T+1]) ok=0;
        }
        if(ok)ans.push_back(T);
    }
    printf("%d\n",ans.size());
    for(auto x: ans) {
        printf("%d ", x);
    }
}