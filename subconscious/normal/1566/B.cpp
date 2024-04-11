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
const int N=3e6+5,mod=1e9+7;
char s[N];
int T,n;
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%s",s+1);n=strlen(s+1);
        int flag=0;
        rep(i,n)if(s[i]=='0'){
            flag=1;
            int j=i+1;
            for(;j<=n&&s[j]=='1';++j);
            if(j<=n&&j!=i+1){flag=2;break;}
        }
        printf("%d\n",flag);
    }

    return 0;
}
/*
XFOF.XFOFX
XFOFXFOF
6+10+12
9+7
*/