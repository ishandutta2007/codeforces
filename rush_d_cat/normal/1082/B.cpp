#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 100000 + 10;
int n; char s[N];
int pre[N],nex[N];
int main(){
    scanf("%d%s",&n,s+1);

    for(int i=1;i<=n;i++){
        if(s[i]=='S')pre[i]=i;
        else pre[i]=pre[i-1];
    }
    nex[n+1]=n+1;
    for(int i=n;i>=1;i--){
        if(s[i]=='S')nex[i]=i;
        else nex[i]=nex[i+1];
    }

    int tot=0;
    for(int i=1;i<=n;i++)if(s[i]=='G')tot++;

    int ans=0;
    if(tot==n){
        ans=n;
    }

    for(int i=1;i<=n;i++){
        if(s[i]=='S'){
            int l=pre[i-1];
            int r=nex[i+1];
            //printf("i=%d, [%d,%d]\n", i,l,r);
            int c=(i-1)-l + r-(i+1);
            
            ans = max(ans,(i-1)-pre[i-1]);
            ans = max(ans,nex[i+1]-(i+1));
            if(c < tot) {
                ans = max(ans, c+1);
            } else {
                ans = max(ans, c);
            }
        }
    }
    printf("%d\n", ans);
}