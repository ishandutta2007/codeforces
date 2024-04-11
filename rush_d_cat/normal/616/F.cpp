#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int N =1000000 + 100;
typedef long long LL;
int s[N];int n,q;
int height[N],rk[N],sa[N],cc[N],t1[N],t2[N],id[N],len[N]; LL sum[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k>=n?-1:y[a+k];
    int b1=y[b],b2=b+k>=n?-1:y[b+k];
    return a1==b1&&a2==b2;
}
void buildSA(int m) {
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++) cc[i]=0;
    for(int i=0;i<n;i++) cc[x[i]=s[i]]++;
    for(int i=1;i<m;i++) cc[i]+=cc[i-1];
    for(int i=n-1;i>=0;i--) sa[--cc[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++)
            if(sa[i]>=k) y[p++]=sa[i]-k;

        for(int i=0;i<m;i++) cc[i]=0;
        for(int i=0;i<n;i++) cc[x[y[i]]] ++;
        for(int i=1;i<m;i++) cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--) sa[--cc[x[y[i]]]]=y[i];
        swap(x,y);
        m=1,x[sa[0]]=0;
        for(int i=1;i<n;i++) {
            x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?m-1:m++;
        }
        if(m>=n) break;
    }
}
void buildH(){
    for(int i=0;i<n;i++)
        rk[sa[i]]=i;
    int k=0; height[0]=0;
    for(int i=0;i<n;i++) {
        if(!rk[i]) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}
int strcnt,c[N]; char str[N];
int L[N],R[N];
int stk[N],top=0;
void Stack_init() {
    for(int i=0;i<n;i++) sum[i]=c[id[sa[i]]];
    for(int i=n;i>=1;i--) height[i]=height[i-1],sum[i]=sum[i-1];
    sum[0]=0; for(int i=1;i<=n;i++)sum[i]+=sum[i-1];

    stk[top=1] = 0; height[0]=-1, height[n+1]=-1;
    for(int i=1;i<=n;i++){
        while(top && height[i]<=height[stk[top]]) top--;
        L[i]=stk[top]; stk[++top]=i;
    }
    stk[top=1] = n+1;
    for(int i=n;i>=1;i--){
        while(top && height[i]<=height[stk[top]]) top--;
        R[i]=stk[top]; stk[++top]=i;
    }
}

int main(){
    scanf("%d",&strcnt);
    for(int i=1;i<=strcnt;i++){
        scanf("%s",str);
        int l=strlen(str);
        for(int j=0;str[j];j++) id[n]=i,s[n]=str[j],len[n++]=l-j;
        s[n++]=1000+i;
    }
    for(int i=1;i<=strcnt;i++) scanf("%d",&c[i]);

    buildSA(120000); buildH(); Stack_init();
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(height[i]<len[sa[i-1]] && height[i+1]<len[sa[i-1]])
            ans=max(ans,(sum[i]-sum[i-1])*len[sa[i-1]]);
        ans=max(ans,height[i]*(sum[R[i]-1]-(L[i]>=0?sum[L[i]-1]:0)) );
    }   
    cout<<ans<<endl;
}