#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mst(head,x,n) memset(head+1,x,n*sizeof(head[0]))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=2e6+5;
int n,m,k;
int a[maxn],c[maxn],b[maxn];
int ans,tmp,cnt;
int flag;
int d[maxn];
bool ok[maxn];
template <typename T>
inline void read(T &X){
    X=0;int w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    if(w) X=-X;
}
int jud(int x){
    int res=b[0]-x;
    rep(i,1,n-1){
        if(a[i]>res+b[i]) return 0;
        if(res>=a[i]) res=b[i];
        else res=b[i]-(a[i]-res);
    }
    if(res+x>=a[0]) return 1;
    return 2;
}
void solve(){
    rep(i,0,n-1) read(a[i]);
    rep(i,0,n-1) read(b[i]);
    int l=0,r=b[0];
    while(l<=r){
        int mid=(l+r)>>1;
        int ans=jud(mid);
        if(ans==1) {
            puts("YES");
            return ;
        }
        if(!ans) r=mid-1;
        else l=mid+1;
    }
    puts("NO");
}
int main(){
    int T,cas=1;
    read(T);
    while(T--)
    {
        read(n);
        solve();
    }
    return 0;

}