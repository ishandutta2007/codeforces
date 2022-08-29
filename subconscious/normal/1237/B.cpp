#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
const ld eps=1e-9;
const int N=(int)2e6+5;
int n,a[N],b[N],pos[N];
int t[N];
void add(int p){for(;p<N;p+=p&-p)t[p]++;}
int sol(int p){int s=0;for(;p;p-=p&-p)s+=t[p];return s;}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i);
    rep(i,n)scanf("%d",b+i),pos[b[i]]=i;
    int ans=0;
    rep(i,n){
        add(pos[a[i]]);
        int x=sol(pos[a[i]]);
        if(x!=i)++ans;
    }
    printf("%d\n",ans);
    return 0;
}