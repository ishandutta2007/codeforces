#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define rd(x) scanf("%d",&x)
#define prt(x) printf("%d\n", x);
#define prtvec(v) for(int i=0;i<v.size();i++) printf("%d%c", v[i], i==(v.size()-1)?'\n':' ');
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,y,x) for(int i=y;i>=x;i--)

const int N=200000+10;
const double EPS = 1e-8;
int n; char s[N];
int main(){
    rd(n);
    scanf("%s",s);
    if (n==1) {
        printf("%s", s);
        return 0;
    }
    int cnt=0;
    for(int i=0;s[i];i++) {
        if(s[i]=='0') cnt++;
    }
    printf("%d", 1);
    for(int i=1;i<=cnt;i++) printf("0");
}