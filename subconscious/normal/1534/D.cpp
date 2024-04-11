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
const int N=2005,mod=1e9+7;
int a[N],b[N];
int n,T;
vector<pr>ans;
int main(){
    scanf("%d",&n);
    printf("? %d\n",1);
    fflush(stdout);
    rep(i,n)scanf("%d",a+i);
    int s=0,to=1;
    for(int i=2;i<=n;++i)if(a[i]&1)++s;
    if(s>n-1-s)to=0;else to=1;
    if(to==0){
        rep(i,n)if(a[i]==1)ans.pb(mp(1,i));
    }
    for(int i=2;i<=n;++i)if(a[i]%2==to){
        printf("? %d\n",i);
        fflush(stdout);
        rep(j,n)scanf("%d",b+j);
        rep(j,n)if(b[j]==1)ans.pb(mp(i,j));
    }
    puts("!");
    for(int i=0;i<n-1;++i)printf("%d %d\n",ans[i].st,ans[i].nd);
    fflush(stdout);
    return 0;
}