#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=100000+10;
int k,n,a[N];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL s=0; for(int i=1;i<=n;i++) s+=a[i];
    if(s%k) return !printf("No\n");

    vector<int> ans;
    LL now=0,cnt=0;
    for(int i=1;i<=n;i++){
        now+=a[i]; cnt++;
        if(now==s/k) {
            ans.push_back(cnt); now=0,cnt=0;
        }
        if(now >s/k) return !printf("No\n");
    }
    printf("Yes\n");
    for(auto x:ans)printf("%d ", x);
}