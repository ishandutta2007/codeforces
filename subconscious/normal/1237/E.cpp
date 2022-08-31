#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
typedef long double ld;
const ld eps=1e-9;
const int N=(int)2e6+5,mod=998244353;
int n;bool s[N];
int main(){
    int now=1,typ=1;
    for(;;){
        //printf("%d\n",now);
        if(now>N)break;
        s[now]=s[now+1]=1;
        now=now*2+1+typ,typ^=1;
    }
    scanf("%d",&n);
    printf("%d\n",s[n]);
    return 0;
}