#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5 + 1;

int n, len, sum;
char s[N];

int main(){
    scanf("%d", &n);
    while(n--){
        sum = 0;
        scanf("%s", s);
        len = strlen(s);
        for (char *c = s; *c; c++)
            sum += *c - 'a' + 1;
        if(len & 1){
            sum -= min(s[0], s[len - 1]) - 'a' + 1;
            int bob = min(s[0], s[len - 1]) - 'a' + 1;
            if(sum > bob){
                printf("Alice %d\n", sum - bob);
            }else{
                printf("Bob %d\n", bob - sum);
            }
        }else
            printf("Alice %d\n", sum);
    }
    return 0;
}