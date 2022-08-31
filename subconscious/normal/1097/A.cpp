#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuck
#define y0 fuxk
#define y1 fxck
#define x1 fxxk
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=0x3f3f3f3f,MOD=998244353;
const ld eps=1e-9;
char s[10][3];
int main(){
    rep(i,6)scanf("%s",s[i]);
    rep(i,5)if(s[1][0]==s[i+1][0]||s[1][1]==s[i+1][1]){puts("YES");return 0;}
    puts("NO");
}