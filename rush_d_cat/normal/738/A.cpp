#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int NICO = 1002;
char s[NICO];
int ok[NICO];
int main()
{
    int n;cin >> n;
    scanf("%s", s+1);
    for(int i=1;i<=n;i++) ok[i] = 1;
    for(int pos=1;pos<=n;pos++)
    {
        if(s[pos] == 'o' && s[pos+1] == 'g' && s[pos+2] == 'o')
        {
            int tmp = pos;
            while(s[pos+1] == 'g' && s[pos+2] == 'o')
            {
                ok[pos] = 0, ok[pos+1] = 0, ok[pos+2] = 0;
                pos += 2;
            }
            ok[tmp] = 2, ok[tmp+1] = 2, ok[tmp+2] = 2;
        } 
    }
    for(int i=1;i<=n;i++)
    {
        if(ok[i] == 1) printf("%c",s[i]);
        if(ok[i] == 2) printf("*");
    }
}