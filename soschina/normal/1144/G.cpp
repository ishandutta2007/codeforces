#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int n, a[N], pos[N], stk[N] = {-1}, top;
bool ans[N];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int lastlds = 0x7fffffff;
    bool flag = true, used = false;
    for (int i = 1; i <= n && flag; i++){
        if(a[i] > stk[top]){
            stk[++top] = a[i];
            pos[top] = i;
        }
        else{
            if(!used && stk[top] < lastlds){
                lastlds = min(lastlds, stk[top]);
                top--;
            }
            if(a[i] <= stk[top]){
                if(a[i] >= lastlds)
                    flag = false;
                else{
                    used = true;
                    lastlds = min(lastlds, a[i]);
                }
            }
            else{
                stk[++top] = a[i];
                pos[top] = i;
                used = false;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans[i] = 1;
    for (int i = 1; i <= top; i++)
        ans[pos[i]] = 0;
    puts(flag ? "YES" : "NO");
    if(flag)
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}