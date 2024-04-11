#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char s[100];int n;
    scanf("%s%d",s,&n);
    if(s[0]=='f'&&n==1)puts("L");else
    if(s[0]=='f'&&n==2)puts("R");else
    if(s[0]=='b'&&n==1)puts("R");else
    if(s[0]=='b'&&n==2)puts("L");
    return 0;
}