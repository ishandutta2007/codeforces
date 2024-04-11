#include <iostream>
#include <cstring>
using namespace std;
int n;
char s[100];
int main()
{
    scanf("%d", &n);
    int ans = 0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%s", s+1);
        if(s[1] == 'T')
        {
            ans += 4;
        }
        if(s[1] == 'C')
        {
            ans += 6;
        }
        if(s[1] == 'O')
        {
            ans += 8;
        }
        if(s[1] == 'D')
        {
            ans += 12;
        }
        if(s[1] == 'I')
        {
            ans += 20;
        }
    }
    cout << ans << endl;
}