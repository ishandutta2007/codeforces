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
const int N=1e5+5;
const ld PI=acos(-1),eps=1e-12;
int a[N],n,T;
bool sol(){
    rep(tim,n){
        bool flag=0;
        //for(int i=n-tim+1;i;--i)printf("%d %d\n",a[i],i+1);
        for(int i=n-tim+1;i;--i)if(a[i]%(i+1)!=0){
            for(int j=i;j<n-tim+1;++j)
                a[j]=a[j+1];
            flag=1;
            break;
        }
        if(!flag)return 0;
    }
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        puts(sol()?"YES":"NO");
    }
    return 0;
}
/*
1.000000 -12.904762 40.476190 -28.571429
3.000000 11.607143 -34.424603 22.817460
*/