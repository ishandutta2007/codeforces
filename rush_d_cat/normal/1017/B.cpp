#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int n;
LL c[4];
char s[N],t[N];
int main() {
    scanf("%d %s %s", &n, s+1, t+1);
    for(int i=1;i<=n;i++) {
        if(s[i]=='0'&&t[i]=='0') c[0]++;
        if(s[i]=='0'&&t[i]=='1') c[1]++;
        if(s[i]=='1'&&t[i]=='0') c[2]++;
        if(s[i]=='1'&&t[i]=='1') c[3]++;
    }
    LL ans = c[0]*(c[2]+c[3]) + c[1]*(c[2]);
    cout<<ans<<endl;
}