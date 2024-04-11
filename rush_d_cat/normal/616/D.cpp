#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000000+10;
int n,k,a[N],c[N];
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0,L=1,R=1;
    for(int l=1,r=1;l<=n;l++){
        while(r<=n && cnt<=k) {
            c[a[r]]++;
            if(c[a[r]]==1)cnt++;
            r++;
            if(cnt>k) break;
            if(r-1-l>=R-L){
                R=r-1,L=l;
            }
        }
        c[a[l]] --; if(c[a[l]]==0) cnt--;
    }
    printf("%d %d\n", L,R);
}