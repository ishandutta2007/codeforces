#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklgl
#define y1 fucklyw
#define eb emplace_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long long i128;
typedef pair<int,int> pr;
const int N=1e6+5;
const ll mod=1e9+9,mod2=1e9+7;
const ld eps=1e-12;
struct node{
    int x,y,d;
}a[N];
bool cmp(node a,node b){return a.d>b.d;}
int n,d[N],lk[N],top;
vector<pr>ans;
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",&a[i].d),a[i].x=2*i-1,a[i].y=2*i;
    sort(a+1,a+n+1,cmp);
    rep(i,n-1)ans.eb(mp(a[i].x,a[i+1].x));
    top=n;rep(i,n)lk[i]=a[i].x;
    rep(i,n){
        int now=i+a[i].d;
        if(lk[now]==0)lk[now]=a[i].y;
        ans.eb(mp(lk[now-1],a[i].y));
    }
    for(pr p:ans)printf("%d %d\n",p.st,p.nd);
    return 0;
}