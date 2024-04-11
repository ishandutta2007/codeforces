#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

char s[1002];
int cnt[1002], k;

int main()
{
    scanf("%s %d", s + 1, &k);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) 
    {
        cnt[s[i]] ++;
    }

    int count = 0; 
    for (int i = 'a'; i <= 'z'; i ++)
    {
        if(cnt[i] >= 1) count ++;
    }

    if(count >= k)
    {
        printf("0\n");
    }
    else
    if(n < k)
    {
        printf("impossible\n");
    }
    else
    {
        printf("%d\n", k - count);
    }

}