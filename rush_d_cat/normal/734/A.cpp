#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100000+10];
int main()
{
    int len;
    scanf("%d", &len);
    scanf("%s", s+1);
    int a=0, d=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i] == 'A') a++;
        if(s[i] == 'D') d++;
    }
    if(a>d) cout << "Anton";
    if(a==d)cout << "Friendship";
    if(a<d) cout << "Danik";
}