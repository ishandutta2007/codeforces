#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=300000+10;
const LL MOD=1e9+7;
LL ans=0, res[N];

using namespace std;
char s[N],tmp[N]; int n;
int sa[N],height[N],rk[N],cc[N],t1[N],t2[N];
int par[N],c1[N],c2[N],c3[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
bool cmp(int *y,int a,int b,int k){
    int a1=y[a],a2=a+k<n?y[a+k]:-1;
    int b1=y[b],b2=b+k<n?y[b+k]:-1;
    return a1==b1 && a2==b2;
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
        for(int i=1;i<n;i++)x[sa[i]]=cmp(y,sa[i],sa[i-1],k)?m-1:m++;
        if(m>=n)break;
    }
}
vector<int> H[N];
void buildH(){
    for(int i=0;i<n;i++)rk[sa[i]]=i;
    height[0]=0; int k=0;
    for(int i=0;i<n;i++){
        if(!rk[i])continue;
        if(k)k--;
        int j=sa[rk[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
        H[k].push_back(rk[i]);
    }
}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(x==y)return;
    //printf("x=%d, y=%d\n", x,y);
    ans -= 1LL*c1[x]*c2[x]*c3[x];
    ans -= 1LL*c1[y]*c2[y]*c3[y];
    c1[y]+=c1[x], c2[y]+=c2[x], c3[y]+=c3[x]; par[x]=y;
    ans += 1LL*c1[y]*c2[y]*c3[y];
    //printf("$ %d %d %d %d %d %d\n", c1[x],c2[x],c3[x], c1[y],c2[y],c3[y]);
}   
int main(){
    int L=N, L1,L2,L3;
    scanf("%s",tmp); for(int i=0;tmp[i];i++) s[n++]=tmp[i]; s[n++]='#'; L=min(L,L1=(int)strlen(tmp));
    scanf("%s",tmp); for(int i=0;tmp[i];i++) s[n++]=tmp[i]; s[n++]='$'; L=min(L,L2=(int)strlen(tmp));
    scanf("%s",tmp); for(int i=0;tmp[i];i++) s[n++]=tmp[i]; L=min(L,(int)strlen(tmp));

    buildSa(1000); buildH();
    for(int i=0;i<N;i++)par[i]=i;
    for(int i=0;i<n;i++){
        if(sa[i]<L1)c1[i]=1;
        else if(L1<sa[i] && sa[i]<L1+1+L2)c2[i]=1;
        else if(sa[i]>L1+1+L2) c3[i]=1;
        //printf("%s %d (%d,%d,%d)\n", s+sa[i], height[i],c1[i],c2[i],c3[i]);
        if(height[i]>=L) unite(i,i-1);
    }
    res[L]=ans;
    for(int lcp=L-1;lcp>=1;lcp--){
        for(auto x: H[lcp]){
            unite(x,x-1);
        }
        res[lcp]=ans;
    }
    for(int i=1;i<=L;i++)
        printf("%lld ", res[i]%MOD);
}