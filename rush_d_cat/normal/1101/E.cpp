#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n;
char op[2]; int x,y;
int main(){
    scanf("%d",&n);
    int a=0,b=0;
    for(int i=1;i<=n;i++){
        scanf("%s%d%d",op,&x,&y);
        if(x>y)swap(x,y);
        if(op[0]=='+'){
            a=max(a,x); b=max(b,y);
        } else {
            if(x>=a && y>=b) printf("YES\n");
            else printf("NO\n");
        }
    }
}