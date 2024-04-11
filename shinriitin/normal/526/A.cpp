#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN=110;

int n;

char a[MAXN];

inline bool check(int l){
    int cnt;
    for(int i=1;i<=n;++i)
        if(a[i]=='*'){
            cnt=0;
            for(int j=i+l;j<=n&&a[j]=='*';j+=l)++cnt;
            if(cnt>=4)return 1;
        }
    return 0;
}

int main(){
    scanf("%d%s",&n,a+1);
    for(int i=1;i<=n;++i)
        if(check(i)){
            puts("yes");
            return 0;
        }
    puts("no");
    return 0;
}