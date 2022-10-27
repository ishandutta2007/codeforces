#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N=100000+10;
int k,n; char s[N];
int sa[N],height[N],rk[N],cc[N],t1[N],t2[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k<n?y[a+k]:-1;
    int b1=y[b],b2=b+k<n?y[b+k]:-1;
    return a1==b1&&a2==b2;
}
void buildSa(int m){
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++)cc[i]=0;
    for(int i=0;i<n;i++)cc[x[i]=s[i]]++;
    for(int i=1;i<m;i++)cc[i]+=cc[i-1];
    for(int i=n-1;i>=0;i--)sa[--cc[x[i]]]=i;

    for(int k=1;k<=n;k<<=1){
        int p=0;
        for(int i=n-k;i<n;i++)y[p++]=i;
        for(int i=0;i<n;i++)
            if(sa[i]>=k)y[p++]=sa[i]-k;

        for(int i=0;i<m;i++)cc[i]=0;
        for(int i=0;i<n;i++)cc[x[y[i]]]++;
        for(int i=1;i<m;i++)cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--)sa[--cc[x[y[i]]]]=y[i];
        swap(x,y); m=1; x[sa[0]]=0;
        for(int i=1;i<n;i++){
            x[sa[i]]=cmp(y,sa[i],sa[i-1],k)?m-1:m++;
        }
        if(m>=n) break;
    }
}
void buildH(){
    for(int i=0;i<n;i++) rk[sa[i]]=i;
    height[0]=0; int k=0;
    for(int i=0;i<n;i++){
        if(!rk[i])continue;
        if(k)--k;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}
int st[N][20],LG[N];
void Rmq_init() {
    for(int i=1;i<N;i++)LG[i]=log2(i);
    for(int i=0;i<n;i++) {
        st[i][0]=height[i];
    }
    for(int j=1;j<20;j++){
        for(int i=0;i<n;i++){
            if(i+(1<<j) <= n)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int Lcp(int i,int j){
    i++;
    int len = j-i+1; int k = LG[len];
    return min(st[i][k], st[j-(1<<k)+1][k]);
}
int main(){
    scanf("%s%d",s,&k); n=strlen(s);
    buildSa(1000); buildH(); Rmq_init();

    int now=0;
    for(int i=0;i<n;i++){
        //printf("%s\n", s+sa[i]);
        for(int j=sa[i]+height[i];j<n;j++){
            int det = 0;
            //printf("i=%d, Lcp=%d, j=%d, height=%d\n", i,Lcp(i,i+1),j,height[i]);
            if(Lcp(i,i+1) < j-sa[i]+1)  det=1;
            else {
                int lef=i+1,rig=n;
                //printf("lef=%d,rig=%d\n", lef,rig);
                while(rig-lef>1){
                    int mid=(lef+rig)>>1;
                    //printf("mid=%d ,Lcp=%d %d\n",mid,Lcp(i,mid),j-i+1);
                    if(Lcp(i,mid) >= j-sa[i]+1) lef=mid;
                    else rig=mid;
                }
                det=lef-i+1;
            }
            now+=det;
            //printf("det=%d\n", det);
            
            if(now>=k) {
                for(int x=sa[i];x<=j;x++){
                    printf("%c", s[x]);
                }
                return 0;
            }
            
        }
    }
    printf("No such line.\n");
}