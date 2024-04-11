#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 300000+10;
int n,h,a[N],b[N];
bool check(int x){
    for(int i=1;i<=x;i++){
        b[i]=a[i];
    }
    sort(b+1,b+1+x);
    LL sum=0;
    for(int i=x;i>=1;i-=2) {
        sum+=b[i];
    }
    return sum<=h;
}
int main() {
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        if(check(i)) return !printf("%d\n", i);
    }
}