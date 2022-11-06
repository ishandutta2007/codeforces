#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int a[100005];
int t[100005];
int q[100005];
void combine(int low, int mid, int high){
    int i;
    int l=low, r=mid+1;
    for(i=0; l<=mid && r<=high; ++i){
        if(a[l]<=a[r]){
            t[i]=a[l++];
        }
        else{
            t[i]=a[r++];
        }
    }
    if(l<=mid){
        while(l<=mid){
            t[i++]=a[l++];
        }
    }
    else{
        while(r<=high){
            t[i++]=a[r++];
        }
    }
    for(i=low; i<=high; ++i){
        a[i]=t[i-low];
    }
}
void msort(int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        msort(low, mid);
        msort(mid+1, high);
        combine(low, mid, high);
    }
}

main()
{
    int n,b,f=0,x,i,j,k,ans=0;
    scanf("%d", &n);
    a[0]=0;
    for(i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        q[i]=0;
    }
    msort(0, n);
    k=n;
    for(i=n;i>0;i--) {
        k--;
        while(a[k]>=a[i]) k--;
        if(k==0) break;
        ans++;
    }
    printf("%d\n", ans);
}