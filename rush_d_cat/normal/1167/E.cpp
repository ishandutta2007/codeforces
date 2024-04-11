#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1000000 + 10;
int n,x,a[N];
int L[N],R[N];
int pre[N],suf[N];

int main() {
    for(int i=0;i<N;i++){
        L[i]=N,R[i]=0;
    }
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        L[a[i]]=min(L[a[i]],i);
        R[a[i]]=max(R[a[i]],i);
    }

    int prelen=0,suflen=x+1;
    for(int i=1;i<=x;i++){
        if(R[i]==0){
            pre[prelen+1]=pre[prelen]; ++prelen;
        } else {
            if(L[i]>pre[prelen]) {
                pre[prelen+1]=R[i]; ++prelen;
            } else {
                break;
            }
        }
    }
    suf[suflen]=n+1;
    for(int i=x;i>=1;i--){
        if(R[i]==0){
            suf[suflen-1]=suf[suflen]; --suflen;
        } else {
            //printf("i=%d\n", i);
            if (R[i]<suf[suflen]) {
                suf[suflen-1]=L[i]; --suflen;
            } else {
                break;
            }
        }
    }
    //printf("%d %d\n", prelen, suflen);
    LL ans=0;
    for(int i=x+1;i>=max(suflen,2);i--) {
        // use [i,x]
        int lef=0,rig=min(i-2,prelen)+1;
        while(rig-lef>1){
            int mid=(lef+rig)>>1;
            if(pre[mid]<suf[i]){
                lef=mid;
            } else {
                rig=mid;
            }
        }
        ans=ans+(lef+1);
    }
    cout<<ans<<endl;
}