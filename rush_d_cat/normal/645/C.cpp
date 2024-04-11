#include <iostream>
using namespace std;
const int N=200000+10;
int n,k;
char a[N];
int p[N],tot,id[N];
int f(int i,int mid){
    int d1 = p[i] - p[i-mid];
    int d2 = p[i+k-mid] - p[i]; 
    if(i+k-mid>tot) d2=1e9;
    //printf("# %d %d %d %d\n", i,k,mid,tot);
    //printf("%d %d %d\n", i,mid,max(d1,d2));
    return max(d1,d2);   
}
int main(){
    scanf("%d%d%s",&n,&k,a+1);
    for(int i=1;i<=n;i++){
        a[i]-='0';
        if(a[i]==0) {
            p[++tot]=i;
            id[i]=tot;
        }
    }
    int ans=1e9;
    for(int i=1;i<=tot;i++) {
        int l=0,r=min(i-1, k);
        while(r-l>1){
            int mid=(l+r)>>1;
            int d1 = p[i] - p[i-mid];
            int d2 = p[i+k-mid] - p[i]; 
            if(i+k-mid>tot) d2=1e9;
            if(d1<d2) {
                l=mid;
            } else {
                r=mid;
            }
        }
        //printf("ok %d\n", l);
        for(int j=max(l-2,0);j<=min(l+2,min(i-1,k));j++)    
            ans=min(ans, f(i,j));
    }
    cout<<ans<<endl;
}