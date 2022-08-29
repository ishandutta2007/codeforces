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
const int mod=1e9+7,N=2e5+5;
int n,a[N],p[N],mi,mx;
bool check(){
    mi=mx=p[n];
    rev(i,n-1)if(p[i]==mi-1)--mi;
    else if(p[i]==mx+1)++mx;
    else return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    rep(i,n)scanf("%d",a+i),p[a[i]]=i;
    puts(check()?"YES":"NO");
    return 0;
}