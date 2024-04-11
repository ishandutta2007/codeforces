#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuck
#define y0 fuxk
#define x1 fxck
#define y1 fxxk
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,MOD=1e9+7;
const ld eps=1e-9;
int n,s;
int d[N];
int main(){
    scanf("%d%d",&n,&s);   
    rep(i,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        ++d[x],++d[y];
    }
    int ans=0;
    rep(i,n)if(d[i]==1)++ans;
    printf("%.15Lf\n",2.L*s/ans);
    return 0;
}