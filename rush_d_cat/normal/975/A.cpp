
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
int n;
char s[N];
set< set<int> > st;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s",s);
        set<int> t;
        for(int j=0;s[j];j++) {
            t.insert(s[j]);
        }
        st.insert(t);
    }
    cout<<st.size()<<endl;
}