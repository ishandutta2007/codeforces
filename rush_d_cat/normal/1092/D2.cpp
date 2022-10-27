#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000+10;
int n,a[N];
int stk[N],top=0;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(top==0) {
            stk[++top]=a[i];
        } else {
            if(stk[top]==a[i]) top--;
            else {
                if(a[i]>stk[top]) return !printf("NO\n");
                stk[++top]=a[i];
            }
        }
    }
    if(top==1){
        if(stk[top]==*max_element(a+1,a+1+n)) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    if(top>=2) printf("NO\n");
    else printf("YES\n");
}