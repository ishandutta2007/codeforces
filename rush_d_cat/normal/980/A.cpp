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
char s[N];
int main(){
    scanf("%s", s);
    int len = strlen(s);
    int c1 = 0, c2 = 0;
    for(int i=0;i<len;i++) {
        if(s[i]=='o') c1++;
        if(s[i]=='-') c2++;
    }   

    if(c2==0) {
        return !printf("YES\n");
    }
    if(c1==0) {
        return !printf("YES\n");
    }
    if(c2%c1==0) {
        return !printf("YES\n");
    }
    printf("NO\n");
}