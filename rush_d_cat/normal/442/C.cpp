#include <iostream>
#include <algorithm>
using namespace std;
const int N=500000+10;
typedef long long LL;
int n,a[N]; LL ans; 
int stk[N],top;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    stk[++top]=1,stk[++top]=2;
    for(int i=3;i<=n;i++){
        while(top>=2 && a[stk[top]]<=a[stk[top-1]] && a[stk[top]]<=a[i]) {
            ans += min(a[stk[top-1]],a[i]); top--;
        } 
        stk[++top]=i;
    }
    for(int i=1;i<=top;i++)stk[i]=a[stk[i]];
    sort(stk+1,stk+1+top);
    for(int i=1;i<=top-2;i++)ans+=stk[i];
    cout<<ans<<endl;
}