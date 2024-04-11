#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
char s[N];int n,q;
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
vector<int> v1,v2;
void brute() {
    LL ans = 0;
    for(auto x: v1) {
        for(auto y: v2) {
            ans += LCP(x-1,y-1);
            //printf("x=%d, y=%d, LCP=%d\n", x,y,LCP(x-1,y-1));
        }
    }
    printf("%lld\n", ans);
}
int L[N],R[N];
int stk[N],top=0;
void Stack_init() {
    for(int i=n;i>=1;i--) height[i]=height[i-1];
    stk[top=1] = 0; height[0]=-1, height[n+1]=-1;
    for(int i=1;i<=n;i++){
        while(top && height[i]<height[stk[top]]) top--;
        L[i]=stk[top]; stk[++top]=i;
    }
    stk[top=1] = n+1;
    for(int i=n;i>=1;i--){
        while(top && height[i]<=height[stk[top]]) top--;
        R[i]=stk[top]; stk[++top]=i;
    }
}
LL sum1[N],sum2[N];
void clever() {
    for(int i=1;i<=n+1;i++)sum1[i]=sum2[i]=0;
    for(auto x:v1) sum1[rk[x-1]+1] ++;//printf("! %d\n", rk[x-1]+1);
    for(auto y:v2) sum2[rk[y-1]+1] ++;//printf("# %d\n", rk[y-1]+1);
    LL ans=0;
    for(int i=1;i<=n+1;i++){ 
        ans += (n-sa[i-1])*sum1[i]*sum2[i];
        sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];
    }
    for(int i=1;i<=n;i++){
        ans += ( (sum1[i-1]-(L[i]?sum1[L[i]-1]:0))*(sum2[R[i]-1]-sum2[i-1]) + 
        (sum2[i-1]-(L[i]?sum2[L[i]-1]:0))*(sum1[R[i]-1]-sum1[i-1]) ) * height[i];
    }
    printf("%lld\n", ans);
}

void check(){
    for(int i=0;i<n;i++){
        printf("%s %d [%d,%d]\n", s+sa[i], height[i+1],L[i+1],R[i+1]);
    }
}

int main(){
    scanf("%d%d",&n,&q);
    scanf("%s", s);
    buildSA(1000); buildH(); RmqInit(); Stack_init(); //check();

    for(int i=1;i<=q;i++) {
        int K,L; scanf("%d%d",&K,&L);
        v1.clear(); v2.clear();
        while(K--){
            int x;scanf("%d",&x); v1.push_back(x);
        }
        while(L--){
            int x;scanf("%d",&x); v2.push_back(x);
        }
        LL sz1 = v1.size(); LL sz2 = v2.size();
        //brute();
        if (sz1 * sz2 <= n) {
            brute();
        } else {
            clever();
        }
    }
}
/*
7 4
abacaba
1 7
1
1 2 3 4 5 6 7
*/