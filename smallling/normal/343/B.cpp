#include<cstdio>

using namespace std;

int top;
char ch,s[1000010];

int main()
{
    char ch=getchar();
    while(ch=='-'||ch=='+')
    {
        if(ch!=s[top])s[++top]=ch;
        else top--;
        ch=getchar();
    }
    if(top)puts("No");
    else puts("Yes");
}