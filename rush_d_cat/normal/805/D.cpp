#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
const int NICO = 1000000+10;
char s[NICO];
LL cnt = 0, sum = 0;
int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    
    LL cnt = 0, sum = 0;

    for(int i=n;i>=1;i--)
    {
        if(s[i] == 'a')
        {
            sum = (sum + cnt) % MOD;
            cnt = cnt * 2 % MOD;
        }
        if(s[i] == 'b')
        {
            cnt ++;
        }
    }
    cout << sum << endl;
}