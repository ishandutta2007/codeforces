#include <iostream>
#include <cstring>
using namespace std;
int n, k;
char s[1000000+10];
int cnt[1002], num[1002];

int main() 
{
    scanf("%d %d", &n, &k);
    
    scanf("%s", s+1);
    
    for(int i=1;i<=n;i++) {
        cnt[s[i]] ++;
    }
    
    int ans = 0, ok = 1;

    for(int i=1;i<=n;i++) 
    {
        num[s[i]] ++;
        if(num[s[i]] == 1) ans ++;
        if(ans > k) ok = 0;

        if(num[s[i]] == cnt[s[i]]) ans --;
        if(ans > k) ok = 0;
    }

    printf("%s\n", ok?"NO":"YES");
}