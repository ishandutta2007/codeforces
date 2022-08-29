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
int T,n,m;
bool in[N];
int main(){
    scanf("%d",&T);
    rep(Cas,T){
        scanf("%d%d",&n,&m);
        rep(i,n)in[i]=0;
        rep(i,m){
            int A,B,C;scanf("%d%d%d",&A,&B,&C);
            in[B]=1;
        }
        rep(i,n)if(!in[i]){
            rep(j,n)if(j!=i)printf("%d %d\n",i,j);
            break;
        }
    }
    return 0;
}
/*
a<=b
c<=d
ac+db-(ad+bc)
=a(c-d)+b(d-c)
=(d-c)(b-a)>=0


*/