#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n,m,a[N];

int main() {
    scanf("%d%d",&n,&m);
    LL sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); sum += a[i];
    }
    sort(a+1,a+1+n);
    LL ans=0;
    int match=0;
    int las=1;
    for(int i=1;i<=n;i++){
        if(a[i]>=las){
            match++;las++;
        }    
    }
    ans = n + a[n] - match;
    ans = sum - ans;
    cout << ans << endl;
}