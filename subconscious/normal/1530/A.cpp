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
const int N=2e6+5,mod=998244353;
const ld eps=1e-10;
int a[N],n,T;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        int x=0;
        while(n>0)x=max(x,n%10),n/=10;
        printf("%d\n",x);
    }
    return 0;
}
/*
*/