#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
#define N 1000000+10
const int MOD = 1000000007;

int n;
char s1[N], s2[N];
map<string, int> mp;

void transfer()
{
    for (int i = 1; i < n; i ++)
    {
        if(s1[i] == 'N') s1[i] = 'S';
        else if(s1[i] == 'S') s1[i] = 'N';
        else if(s1[i] == 'W') s1[i] = 'E';
        else if(s1[i] == 'E') s1[i] = 'W';
    }
}


int main()
{
    scanf("%d", &n);
    scanf("%s %s", s1 + 1, s2 + 1);

    transfer();


    LL str1 = 0, str2 = 0;

    LL temp = 1;

    for (int i = n - 1; i >= 0; i --)
    {
        str1 = ( str1 + (s1[i] - 'A') * temp ) % MOD;
        str2 = ( str2 * 26 + (s2[i] - 'A') ) % MOD;
        temp = temp * 26 % MOD;

        if (str1 == str2)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");


}