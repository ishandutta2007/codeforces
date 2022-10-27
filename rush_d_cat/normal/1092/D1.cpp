#include <iostream>
using namespace std;
const int N = 200000+10;
int n,a[N];
int stk[N],top=0;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);a[i]%=2;
    }
    for(int i=1;i<=n;i++){
        if(top==0) {
            stk[++top]=a[i];
        } else {
            if(stk[top]==a[i])top--;
            else stk[++top]=a[i];
        }
    }
    printf("%s\n", top>=2?"NO":"YES");
}