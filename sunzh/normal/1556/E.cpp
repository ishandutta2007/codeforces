#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return f==-1?~x+1:x;
}
int n,q;
long long a[100010],b[100010];
//psumb-psuma,qujian
//
long long st1[100010][18],st2[100010][18];
int logt[100010];
long long q1(int l,int r){
    int k=logt[r-l+1];
    return max(st1[l][k],st1[r-(1<<k)+1][k]);
}
long long q2(int l,int r){
    int k=logt[r-l+1];
    return min(st2[l][k],st2[r-(1<<k)+1][k]);
}
int main(){
    for(int i=2;i<=100000;++i) logt[i]=logt[i>>1]+1;
    n=read(),q=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int j=1;j<=n;++j) b[j]=read();
    for(int i=1;i<=n;++i) a[i]=b[i]-a[i];
    for(int i=1;i<=n;++i) a[i]+=a[i-1];
    memset(st1,-0x3f,sizeof(st1));memset(st2,0x3f,sizeof(st2));
    for(int i=1;i<=n;++i){
        st1[i][0]=st2[i][0]=a[i];
        // printf("%d\n",a[i]);
    }
    for(int j=1;j<18;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]);
            // printf("i:%d,j:%d,%lld %lld\n",i,j,st1[i][j],st2[i][j]);
            st2[i][j]=min(st2[i][j-1],st2[i+(1<<j-1)][j-1]);
        }
    }
    while(q--){
        int l=read(),r=read();
        long long mn=q2(l,r)-a[l-1],mx=q1(l,r)-a[l-1];
        // printf("mn:%lld,mx:%lld\n",mn,mx);
        if(mn<0||a[l-1]!=a[r]) printf("-1\n");else printf("%lld\n",mx);
    }
}