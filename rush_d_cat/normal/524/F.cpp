#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int N=2000000+10;
char s[N]; int n,pre[N];
const int INF=1e9+7;
int mx[N<<2],mn[N<<2];
vector<int> vec;

void build(int l,int r,int rt){
    if(l==r){
        mn[rt]=mx[rt]=pre[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
int querymin(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return mn[rt];
    int mid=(l+r)>>1,ans=N;
    if(L<=mid)ans=min(ans,querymin(l,mid,rt<<1,L,R));
    if(R >mid)ans=min(ans,querymin(mid+1,r,rt<<1|1,L,R));
    return ans;
}
int querymax(int l,int r,int rt,int L,int R){
    if(L<=l&&r<=R)return mx[rt];
    int mid=(l+r)>>1,ans=-N;
    if(L<=mid)ans=max(ans,querymax(l,mid,rt<<1,L,R));
    if(R >mid)ans=max(ans,querymax(mid+1,r,rt<<1|1,L,R));
    return ans;
}

char str[N];
int height[N],rk[N],sa[N],cc[N],t1[N],t2[N];
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k>=n?-1:y[a+k];
    int b1=y[b],b2=b+k>=n?-1:y[b+k];
    return a1==b1&&a2==b2;
}
void buildSA(int m) {
    int *x=t1,*y=t2;
    for(int i=0;i<m;i++) cc[i]=0;
    for(int i=0;i<n;i++) cc[x[i]=str[i]]++;
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
void init() {
    for(int i=1;i<=n*2;i++) str[i-1]=s[i];
    n=n*2;
    buildSA(1000); buildH();
    n=n/2;
}


int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for(int i=1;i<=n;i++)s[i+n]=s[i];
    for(int i=1;i<=2*n;i++)pre[i]=pre[i-1]+(s[i]=='('?1:-1);
    build(1,2*n,1);
    init();

    int need = pre[n]; 
    pair<int,int> bst = make_pair(INF,0);
    for(int i=1;i<=n;i++){
        int cnt = 0,cntLef=0; 
        //int m1 = querymax(1,n<<1,1, i,i+n-1);
        int m2 = querymin(1,n<<1,1, i,i+n-1);
        if(need <= 0) {
            cnt = -need + max(max(-(m2-pre[i-1]-need), pre[i+n-1]-m2),0)*2; 
            cntLef = -need + max(max(-(m2-pre[i-1]-need), pre[i+n-1]-m2),0);
        } else {
            cnt = +need + max(max(-(m2-pre[i-1]), pre[i+n-1]-m2-need),0)*2; 
            cntLef = max(max(-(m2-pre[i-1]), pre[i+n-1]-m2-need),0);
        }

        if(make_pair(cnt,cntLef)<bst) {
            bst=make_pair(cnt,cntLef); vec.clear();
        }
        if(make_pair(cnt,cntLef)==bst){
            vec.push_back(i);
        }
    }

    int mn = N; int st =0;
    for(auto x: vec)
        if(rk[x-1] < mn) {
            mn = rk[x-1]; st=x;
        }

    for(int i=1;i<=bst.second;i++) printf("(");
    for(int i=st;i<st+n;i++)printf("%c", s[i]);
    for(int i=1;i<=bst.first-bst.second;i++) printf(")");
    printf("\n");
}