#include <iostream>
#include <cstring>
using namespace std;
const int N = 10000+20;
int sa[N],cc[N],t1[N],t2[N],height[N],rk[N];
int n; char s[N], t[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a], a2=(a+k>=n)?-1:y[a+k];
    int b1=y[b], b2=(b+k>=n)?-1:y[b+k];
    return a1==b1 && a2==b2;
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
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;

        for(int i=0;i<m;i++) cc[i]=0;
        for(int i=0;i<n;i++) cc[x[y[i]]]++;
        for(int i=1;i<m;i++) cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--) sa[--cc[x[y[i]]]]=y[i];

        swap(x,y);
        x[sa[0]]=0; m=1;
        for(int i=1;i<n;i++) {
            x[sa[i]] = cmp(y,sa[i],sa[i-1],k) ? m-1 : m++;
        }
        if (m>=n) break;
    }
}
void buildH() {
    for(int i=0;i<n;i++) rk[sa[i]]=i;
    height[0]=0; 
    int k=0;
    for(int i=0;i<n;i++) {
        if(!rk[i]) continue;
        int j=sa[rk[i]-1];
        if(k) k--;
        while(s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

int main() {
    scanf("%s",t); int len1=strlen(t);
    for(int i=0;t[i];i++) s[n++]=t[i];
    s[n++]='#';
    scanf("%s",t);
    for(int i=0;t[i];i++) s[n++]=t[i];

    //printf("%s\n", s);
    buildSa(1000); buildH();

    int ans=1e9+7;
    for(int i=1;i<n;i++) {
        if (height[i]) {
            if ( (sa[i]>=len1 && sa[i-1]<len1) || (sa[i]<len1 && sa[i-1]>=len1) ) {
                if (height[i-1]<height[i] && height[i+1]<height[i]) ans = min(ans, max(height[i-1],height[i+1])+1);
            }
        }
    }
    if(ans==1e9+7) ans=-1;
    printf("%d\n", ans);
}