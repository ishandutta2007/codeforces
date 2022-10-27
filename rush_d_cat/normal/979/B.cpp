#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000000+10;
char s[N];
int n, len;
int mx[4];
int main() {
    scanf("%d",&n);
    for(int i=0;i<3;i++) {
        scanf("%s",s);
        int cnt[3000]; memset(cnt,0,sizeof(cnt));
        len = strlen(s);
        for(int j=0;j<len;j++)
            cnt[s[j]] ++;
        mx[i] = *max_element(cnt,cnt+1000);
        
        if (mx[i] == len && n == 1) {
            mx[i] = len-1;
            continue;
        }

        if (n+mx[i] <= len) {
            mx[i] = mx[i] + n;
        } else {
            mx[i] = len;
        }
    }

    if(mx[0]>mx[1]&&mx[0]>mx[2]) {
        printf("Kuro\n");
    } else
    if(mx[1]>mx[0]&&mx[1]>mx[2]) {
        printf("Shiro\n");
    } else
    if(mx[2]>mx[0]&&mx[2]>mx[1]) {
        printf("Katie\n");
    } else {
        printf("Draw\n");
    }
}