#include<cstdio>
#include<cstring>
char s[1111111];
int main()
{
    scanf("%s",s);int n=strlen(s);
    int S=0,T=0;
    for(int i=0;i<n;i++)
        if(s[i]=='(')T++;
        else if(T)S++,T--;
    printf("%d\n",S*2);
    return 0;
}