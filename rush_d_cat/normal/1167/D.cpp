#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,nex[N],vis[N],ans[N];
char s[N];

int stk[N],top;

void build(int l,int r,int c) {
    int i=l;
    while(1) {
        ans[i]=ans[nex[i]]=c;
        if(i+1!=nex[i])
            build(i+1,nex[i]-1,c^1);
        i=nex[i]+1;
        if(i>=r) break;
    }
}

int main() {
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            stk[++top]=i;
        }else{
            nex[stk[top]]=i; 
            --top;
        }
    }    
    build(1,n,0);
    for(int i=1;i<=n;i++){
        printf("%d", ans[i]);
    }
}