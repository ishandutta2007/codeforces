#include <bits/stdc++.h>
using namespace std;

int T;
int len;
char str[1010];

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%s", str+1);
        len = strlen(str+1);
        sort(str+1, str+len+1);
        if (str[1] == str[len]) printf("-1\n");
        else printf("%s\n", str+1);
    }
    return 0;
}