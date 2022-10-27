#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int NICO = 1000000 + 10;
char s[NICO];
int k;
int main()
{
    scanf("%s", s+1);
    scanf("%d", &k);
    int len = strlen(s+1);
    int cnt = 0, ans = 0;
    for(int i=len;i>=1;i--)
    {
        if(s[i] == '0')
        {
            cnt ++;
        } else {
            ans ++;
        }
        if(cnt == k) break;
    }
    if(cnt != k)
    {
        ans = cnt?(len - 1):len;
    }
    cout << ans << endl;
}