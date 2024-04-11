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
const ld PI=acos(-1);
const int N=1e6+5;
int a[N],n,q[N];
int que(){
    printf("?");
    rep(i,n)printf(" %d",q[i]);
    puts("");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
int main(){
    scanf("%d",&n);
    a[n]=-1;
    for(int now=1;now<n;++now){
        rep(i,n)q[i]=1;
        q[n]+=now;
        if(que()==0){
            a[n]=n+1-now;
            break;
        }
    }
    if(a[n]==-1)a[n]=1;
    rep(i,n){
        if(i==a[n])continue;
        rep(i,n)q[i]=a[n];
        q[n]+=(i-a[n]);
        a[que()]=i;
    }
    printf("! ");
    rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
    fflush(stdout);
    return 0;
}
/*
a<=b
c<=d
ac+db-(ad+bc)
=a(c-d)+b(d-c)
=(d-c)(b-a)>=0


*/