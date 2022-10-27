#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=400000+10;
vector<int> v;
int id(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
int n,I,a[N],cnt[N],sum[N];
int main(){
    scanf("%d%d",&n,&I);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); v.push_back(a[i]);
    }
    I=I*8/n;
    sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++){
        cnt[id(a[i])]++;
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+cnt[i];
    }
    int len=1;
    for(int i=1;i<=I;i++) {
        len=len*2; 
        if(len>=n){
            len=n; break;
        }
    }
    int ans=N;
    for(int i=1;i<=n;i++){
        // [i,i+len)
        if(i+len<=n+1) {
            ans=min(ans, n - (sum[i+len-1]-sum[i-1]));
        }
    }
    printf("%d\n", ans);
}