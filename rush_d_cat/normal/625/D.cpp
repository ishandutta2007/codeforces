#include <iostream>
#include <cstring>
using namespace std;
const int N=100000+10;
char s[N];
int sum[N],a[N],b[N];
void solve(int l,int r,int len){
    if (l>r) return;
    /*
    printf("l=%d,r=%d,len=%d\n", l,r,len);
    for(int i=l;i<=r;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    */
    if (len == r-l+1) {
        b[r]=a[r];     
        if(l!=r && a[l]>=10 && a[r]!=9) b[r]+=10;
        a[r]-=b[r]; 
        if(l!=r) a[l]-=b[r];
        int now=r;
        //printf("now = %d, a[%d] = %d\n", r, r, a[r]);
        while(now>l && a[now]<0){
            a[now-1] -= (-a[now]+9)/10; a[now]+=(-a[now]+9)/10 * 10; --now;
            //printf("now: %d, a = %d\n", now, a[now]);
        } 
            //printf("## l=%d,r=%d,len=%d\n", l,r,len);
    //for(int i=l;i<=r;i++){
        //printf("%d ", a[i]);
    //}
        if(a[l]>0) a[l+1]+=10*a[l],a[l]=0;
        solve(l+1,r-1,len-2);
    } 
}
void chk(int n) {
    //printf("n = %d\n", n);
    int c[N]={0};
    for(int i=n;i>n/2;i--){
        int x=(b[i])/2, y=(b[i]+1)/2;
        b[n-i+1]=x; b[i]=y;
    }
    for(int i=1;i<=n;i++){
        c[i]=b[n-i+1];
    }
    /*
    printf("ans is: ");
    for(int i=n;i>=1;i--){
        printf("%d",b[i]);
    }
    printf("\n");
    */
    for(int i=n;i>=1;i--){
        c[i]=c[i]+b[i];
    }
    for(int i=1;i<=n;i++){
        if(c[i]>=10){
            c[i+1]+=c[i]/10;
            c[i]=c[i]%10;
        }
    }
    int nn=strlen(s+1);
    int d[N]={0};
    for(int i=1;i<=nn;i++)d[i]=s[nn-i+1]-'0';
    bool fg=0;
    for(int i=1;i<N;i++)if(c[i]!=d[i])fg=1;
    for(int i=1;i<N;i++)if(b[i]>=10||b[i]<0)fg=1;
    if(b[n]==0) fg=1;
    if(fg==0){
        for(int i=n;i>=1;i--){
            printf("%d",b[i]);
        }
        exit(0);
    }
}
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);  
    
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    solve(1,n,n); 
    /*
    for(int i=n;i>n/2;i--){
        printf("%d\n", b[i]);
    }
    */
    chk(n);
    
    for(int i=1;i<=n;i++)a[i]=s[i]-'0';
    a[2]=a[1]*10+a[2];
    --n;
    for(int i=1;i<=n;i++)a[i]=a[i+1];
    solve(1,n,n);   
    /*
    printf("!\n");
    for(int i=n;i>n/2;i--){
        printf("%d\n", b[i]);
    }
    */
    chk(n);
    printf("0\n");
    return 0;
}   
/*
2
59994
*/