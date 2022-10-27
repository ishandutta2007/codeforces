#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
char s[N];int n,len;
int height[N],rk[N],sa[N],cc[N],t1[N],t2[N];
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
int LG[N],st[N][20];
void RmqInit() {
    for(int i=1;i<N;i++) {
        int t = i, c = 0;
        while(t>1) { t/=2; c ++; }
        LG[i] = c;
    }
    for(int i=0;i<n;i++)
        st[i][0]=height[i];

    for(int i=1;i<20;i++)
    for(int j=0;j<n;j++)
        if(j+(1<<i)<=n)
            st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
}
int LCP(int x, int y) { // suffix(x) & suffix(y)
    if (x==y) return n-x;
    int l = min(rk[x], rk[y]) + 1;
    int r = max(rk[x], rk[y]); 
    int k = LG[r-l+1];
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

char s1[N],s2[N];
void init() {
    scanf("%s%s",s1,s2);
    len=strlen(s1);
    for(int i=0;i<len;i++)s[n++]=s1[i]; s[n++]='#';
    for(int i=0;s2[i];i++)s[n++]=s2[i];
    buildSA(1000); buildH(); RmqInit();
}
vector<int> vec[N];
bool cmp2(int x,int y){
    return rk[x]<rk[y];
}
int sum[N];
void solve(){
    LL ans=0;
    for(int i=0;i<len;i++){
        int lcp = LCP(i+1,len+1);
        sum[i+1]++,sum[i+1+lcp]--;
        if(len+lcp+1<n) vec[i+lcp].push_back(len+lcp+1);
    }
    for(int i=0;i<len;i++){
        sort(vec[i].begin(),vec[i].end(),cmp2);
        for(int j=0;j<vec[i].size();j++){
            int lcp = (j>=1) ? LCP(vec[i][j],vec[i][j-1]) : 0;
            ans += n-vec[i][j]-lcp;
        }
    }
    for(int i=1;i<len;i++){
        sum[i]+=sum[i-1]; if(sum[i])ans++;
    }
    cout<<ans<<endl;
}

int main(){
    init();
    solve();
}