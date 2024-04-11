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
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=1e6+5,inf=1e9+7;
int a[N],n,T;
ll s;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        sort(a+1,a+n+1);
        int l=1,r=n+1;
        ll s=a[1];
        while(s>=0&&l<r){
            ++l,--r;
            if(l>=r)break;
            s+=a[l]-a[r];
        }
        puts(s<0?"YES":"NO");
    }
    return 0;
}
/*


*/