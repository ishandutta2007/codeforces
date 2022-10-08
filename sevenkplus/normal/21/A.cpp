#include<cstdio>
#include<cstring>
#define EX() \
{\
    puts("NO");\
    return 0;\
}
#define EY() \
{\
    puts("YES");\
    return 0;\
}
int main()
{
    char s[1000];
    scanf("%s",&s);
    int n=strlen(s);
    int i=0;
    while(s[i]!='@')
    {
        if(i==16)
            EX();
        if(!(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||('0'<=s[i]&&s[i]<='9')||(s[i]=='_')))
            EX();
        i++;
        if(i==n)
            EX();
    }
    if(i==0)
        EX();
    int la=i,LA=i;
    i++;
    while(i<n&&s[i]!='/')
    {
        if(i-la>16)
            EX();
        if(i-LA>32)
            EX();
        if(!(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||('0'<=s[i]&&s[i]<='9')||(s[i]=='_')))
            EX();
        i++;
        if(s[i]=='.')
        {
            la=i,i++;
        }
    }
    if(i==la+1)
        EX();
    if(i==n)
        EY();
    la=i,i++;
    while(i<n)
    {
        if(i-la>16)
            EX();
        if(!(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||('0'<=s[i]&&s[i]<='9')||(s[i]=='_')))
            EX();
        i++;
        if(s[i]=='/')
        {
            la=i,i++;
        }
    }
    if(i==la+1)
        EX();
    EY();
    return 0;
}