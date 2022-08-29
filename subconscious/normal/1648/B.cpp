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
const int N=1e6+5,mod=998244353;
int n,c,T,a[N],S[N];
bool check(){
    rep(i,c)if(!a[i])rep(j,c){
        if(i*j>c)break;
        if(!a[j])continue;
        if(S[min(c,i*j+j-1)]-S[i*j-1]>0)return 0;
    }
    return 1;
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&c);
        rep(i,c)a[i]=0;
        rep(i,n){
            int x;scanf("%d",&x);
            a[x]=1;
        }
        rep(i,c)S[i]=S[i-1]+a[i];
        puts(check()?"Yes":"No");
    }
    return 0;
}
/*
*/