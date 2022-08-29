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
const int N=1005;
int n,k,mx;
int ans[N][N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j){
            int u=i,v=j;
            while(u!=v)u/=k,v/=k,++ans[i][j];
            mx=max(mx,ans[i][j]);
        }
    printf("%d\n",mx);
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)printf("%d ",ans[i][j]);
    puts("");
    return 0;
}
/*
a<=b
c<=d
ac+db-(ad+bc)
=a(c-d)+b(d-c)
=(d-c)(b-a)>=0


*/