#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckxjb
#define y0 fuxkcjb
#define x1 fxckcjb
#define y1 fuckcxb
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e3+5,MOD=998244353,inf=0x3f3f3f3f;
const ld eps=1e-9;
int n;
int main(){
    scanf("%d",&n);
    int x=0,y=0;
    for(;;){
        printf("%d %d\n",x,y);--n;
        if(n==0)break;
        printf("%d %d\n",x+1,y);--n;
        if(n==0)break;
        printf("%d %d\n",x+1,y+3);--n;
        if(n==0)break;
        x+=2;
    }
    return 0;
}