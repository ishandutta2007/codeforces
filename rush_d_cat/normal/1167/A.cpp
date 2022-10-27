#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int T,n; char s[N];

int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,s+1);
        int pos=-1;
        for(int i=1;i<=n;i++){
            if(s[i]=='8'){
                pos=i; break;
            }
        }
        if(pos==-1) {
            printf("NO\n");continue;
        }
        printf("%s\n", n-pos+1>=11?"YES":"NO");
    }
}