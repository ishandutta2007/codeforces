#include <iostream>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n; LL a[N];
bool chk(LL x){
    LL s=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x)return 0;
        s+=x-a[i];
    }
    return s>=x;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    LL lef=0,rig=2e9;
    while(rig-lef>1){
        LL mid=(lef+rig)>>1;
        if(chk(mid)) rig=mid; else lef=mid;
    }
    cout<<rig<<endl;
}