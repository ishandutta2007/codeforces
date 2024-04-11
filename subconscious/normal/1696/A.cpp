#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
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
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N=3e5+5,mod=1e9+7;
int a[N],n,T,z;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&z);
        rep(i,n)scanf("%d",a+i);
        int ans=0;
        rep(i,n)ans=max(ans,a[i]|z);
        printf("%d\n",ans);
    }
    return 0;
}
/*
3 
1 -1 
1 1
-1 2
*/