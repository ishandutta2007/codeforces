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
const int N=3e6+5,mod=1e9+7;
int a[N],n,T;
int cnt[N];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        rep(i,n)if(i&1)++cnt[a[i]];
        sort(a+1,a+n+1);
        rep(i,n)if(i&1)--cnt[a[i]];
        bool flag=0;
        rep(i,n)if(cnt[a[i]]!=0){flag=1;break;}
        puts(flag?"NO":"YES");
        rep(i,n)cnt[a[i]]=0;
    }
    return 0;
}
/*
 
*/