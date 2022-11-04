#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_N 105

int n;
char s[MAX_N];
bool yes;
int main()
{
	cin>>n;
	getchar();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	    for (int j=1;i+j*4<=n;j++)
	        if(s[i]=='*' && s[i+j]=='*' && s[i+j*2]=='*' && s[i+j*3]=='*' && s[i+j*4]=='*')
	        {
	            yes=true;
	            break;
            }
    if (yes)
        printf("yes");
    else
        printf("no");
	return 0;
}