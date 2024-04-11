#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 5000 + 10;
char s[N<<1]; int n;

int main(){
    scanf("%s", s+1); n=strlen(s+1);

    bool ok=0;
    for(int i=1;i<=n/2;i++){
        if(s[i]!=s[1]) ok=1;
    }
    if(!ok) return !printf("Impossible\n");

    for(int i=1;i<=n;i++){
        s[i+n]=s[i];
    }
    for(int i=1;i<=n;i++){
        int l=i,r=i+n-1;
        bool ok=1;
        for(int j=l;j<=r;j++){
            if(s[j]!=s[l+r-j]) ok=0;
        }
        if(ok==1) {
            bool sam=1;
            for(int j=1;j<=n;j++){
                if(s[j]!=s[l+j-1]) sam=0;
            }
            if(sam==1) ok=0;
        }
        if(ok) return !printf("1\n");
    }
    printf("2\n");
}
/*

*/