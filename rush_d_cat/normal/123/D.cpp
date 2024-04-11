#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int INF = 1e9+7;
int cc[N],sa[N],t1[N],t2[N],height[N],rk[N];
int n;
char s[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k>=n?-1:y[a+k];
    int b1=y[b],b2=b+k>=n?-1:y[b+k];
    return a1==b1&&a2==b2;
}
void buildSa(int m) {
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

void buildH() {
    for(int i=0;i<n;i++) 
        rk[sa[i]]=i;
    
    int k=0;
    height[0]=0; 
    
    for(int i=0;i<n;i++) {
        if(!rk[i]) continue;
        if(k) k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

pair<int,int> stk[N]; int top;
int pre[N], nex[N];
int main() {
    scanf("%s",s); n=strlen(s);
    buildSa(1000);
    buildH();

    top=0, stk[++top] = make_pair(0,-INF);
    for(int i=1;i<n;i++) {
        while(stk[top].second >= height[i]) -- top;
        pre[i] = stk[top].first;
        stk[++top]=make_pair(i,height[i]);
    }
    top=0, stk[++top] = make_pair(n,-INF);
    for(int i=n-1;i>=0;i--) {
        while(stk[top].second > height[i]) -- top;
        nex[i] = stk[top].first;
        stk[++top]=make_pair(i,height[i]);
    }

    LL ans=0;
    for(int i=0;i<n;i++) {
        ans += n-sa[i];
    }
    for(int i=1;i<n;i++) {
        ans+= 1LL*(i-pre[i])*(nex[i]-i)*height[i];
    }
    printf("%lld\n", ans);
}