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
const int N=2e5+5,inf=1e9+7;
int n,a[N],tmp[N],top,b[N],T;
vi pos[N];
set<int>d;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)pos[i].clear();
        d.clear();
        rep(i,n)scanf("%d",a+i),pos[a[i]].pb(i);
        rep(i,n)if(pos[i].size()>0)d.insert(i);
        while(d.size()>0){
            top=0;
            for(int x:d)tmp[++top]=pos[x].back(),pos[x].pop_back();
            d.clear();
            rep(i,top)b[tmp[i]]=a[tmp[i%top+1]];
            rep(i,top)if(pos[a[tmp[i]]].size()>0)d.insert(a[tmp[i]]);
        }
        rep(i,n)printf("%d%c",b[i]," \n"[i==n]);
    }
    return 0;
}
/*
10 5
2 8
6 7
3 7
2 10
7 10
9 5
9 1
5 3
4 5

6 5
1 5
2 1
3 5
4 3
6 5
*/