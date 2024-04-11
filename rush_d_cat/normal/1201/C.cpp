#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2000000 + 10;
typedef long long LL;

int n,k,a[N];
bool ok(LL x){
    int has=0;
    for(int i=1;i<=n;i++) if(a[i]>=x) has++;
    int need=(n+1)/2 - has;
    
    if(need<=0) return 1;
    int pos=-1;
    for(int i=n;i>=1;i--){
        if(a[i]<x) {
            pos=i;
            break;
        }
    }

    LL tot=0;
    for(int i=pos;i>=1;i--){
        if(need) {
            need--; tot+=x-a[i];
            if(tot>k) return 0;
        }
        if(need==0) return 1;
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);

    LL lef=0,rig=1e10;
    while(rig-lef>1){
        LL mid=(lef+rig)>>1;
        if(ok(mid)) lef=mid;
        else rig=mid;
    }
    cout<<lef<<endl;
}