#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 120;
char s[MAXN];
int main()
{
    scanf("%s", s + 1);
    int i, len = strlen(s+1), ans = 0;
    s[0] = 'a';
    for(i = 1; i <= len; i++)
    {
        if(abs(s[i] - s[i-1]) < 13) ans += abs(s[i] - s[i-1]);
        else ans += 26 - abs(s[i] - s[i-1]);
    }
    cout << ans << endl;
}