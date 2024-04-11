#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

map <string, int> mp;

char s[101], ss[101];

int main(){
    //freopen("a.in", "r", stdin);
    scanf("%s", s);
    int len = strlen(s);
    for(int n=len-1; n>=1; n--){
        mp.clear();
        int tot = 0;
        for(int i=0; i<=len-n; i++){
            for(int j=0; j<n; j++) ss[j] = s[i+j];
            ss[n] = NULL;
            if(mp[ss]) {printf("%d\n", n); return 0;}
            mp[ss] = ++tot;
        }
    }
    puts("0");
    return 0;
}