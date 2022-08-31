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
const int N=1e6+5,inf=1e9+7;
int n,T,a[N];
bool flag;
void dfs(int pos,int sum,int typ){
    if(pos==n+1){
        if(typ==0)return;
        if(sum!=0)return;
        flag=1;
        return;
    }
    dfs(pos+1,sum+a[pos],1);
    dfs(pos+1,sum,typ);
    dfs(pos+1,sum-a[pos],1);
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        rep(i,n)scanf("%d",a+i);
        flag=0;
        dfs(1,0,0);
        puts(flag?"YES":"NO");
    }

    return 0;
}