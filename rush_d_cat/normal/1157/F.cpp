#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000+10;
int n,a[N];
int c[N],s[N],cnt[N],sum[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); cnt[a[i]]++;
    }
    for(int i=1;i<N;i++) {
        if(cnt[i]>=2) c[i]=1;
    }
    s[0]=0;
    for(int i=1;i<N;i++)s[i]=s[i-1]+c[i], sum[i]=sum[i-1]+cnt[i];
    int ans=0,l,r;
    for(int i=1;i<N;i++){
        if(cnt[i]){
            int lef=i,rig=N-1;
            while(rig-lef>1){
                int mid=(lef+rig)>>1;
                if(s[mid]-s[i]==mid-i) lef=mid;
                else rig=mid;
            }
            if(cnt[lef+1]==1){
                int tmp=sum[lef+1]-sum[i-1];
                if(tmp>ans){
                    l=i,r=lef+1;ans=tmp;
                }
            } else {
                int tmp=sum[lef]-sum[i-1];
                if(tmp>ans){
                    l=i,r=lef+1;ans=tmp;
                }
            }
            //if(i==1) printf("lef = %d\n", lef);
        }
    }
    printf("%d\n", ans);
    for(int j=1;j<=cnt[l];j++) printf("%d ", l);
    for(int i=l+1;i<r;i++){
        for(int j=1;j<cnt[i];j++){
            printf("%d ", i);
        }
    }
    for(int j=1;j<=cnt[r];j++) printf("%d ", r);
    for(int i=r-1;i>l;i--) {
        printf("%d ", i);
    }
}