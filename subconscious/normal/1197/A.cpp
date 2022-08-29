#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define mp make_pair
#define pb push_back
#define x0 fuckcjb
#define y0 fuckjsb
#define x1 fucklbn
#define y1 fuckyzc
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld eps=1e-10,inf=1e50;
const int mod=1e9+7,N=1e5+5;
int T,n,a[N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        sort(a+1,a+n+1);
        printf("%d\n",min(n-2,a[n-1]-1));
    }
    return 0;
}