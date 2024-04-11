#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000000+10];
int main()
{
    gets(s);
    for(int i=0;s[i];i++)printf("%c",s[i]);
    for(int i=strlen(s)-1;i>=0;i--)printf("%c",s[i]);
    return 0;
}