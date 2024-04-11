#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckjsb
#define y1 fuckjtjl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=0x3f3f3f3f,MOD=1e9+7;
int x,y,z,t1,t2,t3;
int main(){
    scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
    puts(t1*abs(x-y)>=t2*(abs(x-z)+abs(x-y))+3*t3?"YES":"NO");
    return 0;
}