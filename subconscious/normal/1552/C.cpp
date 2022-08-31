#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=1e9+7;
int n,k,T,a[N];
vector<int>vec;
bool check(int a,int b,int c,int d){
    if(a>b)swap(a,b);
    if(c>d)swap(c,d);
    int f1=(a<=c&&c<=b)+(a<=d&&d<=b);
    int f2=(c<=a&&a<=d)+(c<=b&&b<=d);
    return f1==1&&f2==1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&k);n*=2;
        rep(i,n)a[i]=0;
        rep(i,k){
            int x,y;scanf("%d%d",&x,&y);
            a[x]=y;a[y]=x;
        }
        vec.clear();
        rep(i,n)if(a[i]==0)vec.pb(i);
        int siz=vec.size();
        for(int i=0;i<siz;++i)
            a[vec[i]]=vec[(i+siz/2)%siz];
        ll ans=0;
        rep(i,n)rep(j,n){
            if(i==j||a[i]==j)continue;
            if(check(i,a[i],j,a[j]))++ans;
        }
        ans/=8;
        printf("%lld\n",ans);
    }

    return 0;
}