#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n;
char s[100];
int cnt[2][10];
int S,L,M;
int main() {

    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%s", s);
        int len = strlen(s);
        if(len==1) {
            if(s[0]=='S') S++;
            if(s[0]=='L') L++;
            if(s[0]=='M') M++;
        }
        cnt[0][len-1] += (s[len-1]=='S'?1:0);
    }
    for(int i=1;i<=n;i++) {
        scanf("%s", s);
        int len = strlen(s);
        if(len==1) {
            if(s[0]=='S') S--;
            if(s[0]=='L') L--;
            if(s[0]=='M') M--;
        }
        cnt[1][len-1] += (s[len-1]=='S'?1:0);
    }
    int ans=0;
    for(int i=1;i<10;i++) ans += abs(cnt[0][i]-cnt[1][i]);
    if(S>0) ans+=S;
    if(L>0) ans+=L;
    if(M>0) ans+=M; 

    cout<<ans<<endl;
}