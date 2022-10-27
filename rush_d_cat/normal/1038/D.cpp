#include <iostream>
using namespace std;
typedef long long LL;
const int N = 500000+10;

int n,a[N];

int main() {
    scanf("%d",&n);
    LL s=0,mn=1e9+7;
    
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i]<0) s-=a[i], mn=min(mn,-(LL)a[i]);
        else s+=a[i],mn=min(mn,(LL)a[i]);
    }
    if(n==1) {
        cout<<a[1]<<endl; return 0;
    }
    bool ok1=0,ok2=0;
    for(int i=1;i<=n;i++) {
        if(a[i]<=0) ok1=1;
        if(a[i]>=0) ok2=1;
    }
    if(ok1&&ok2) {
        cout<<s<<endl; return 0;
    }
    cout<<s-2*mn<<endl;
}