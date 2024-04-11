#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 105

using namespace std;

char s[10][10];
int n;
bool ans,t,f[10][10];;

int main()
{
	for (int i=0;i<10;i++)
	    scanf("%s",s[i]);
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            f[i][j]=(s[i][j]=='X');
    ans=false;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            if (s[i][j]=='.'){
            	f[i][j]=true;
            	t=false;
            	for (int k=0;k<10;k++)
            	    for (int l=0;l<6;l++)
            	        if (f[k][l]&&f[k][l+1]&&f[k][l+2]&&f[k][l+3]&&f[k][l+4]) t=true;
            	for (int k=0;k<6;k++)
            	    for (int l=0;l<10;l++)
            	        if (f[k][l]&&f[k+1][l]&&f[k+2][l]&&f[k+3][l]&&f[k+4][l]) t=true;
            	for (int k=0;k<6;k++)
            	    for (int l=0;l<6;l++)
            	        if (f[k][l]&&f[k+1][l+1]&&f[k+2][l+2]&&f[k+3][l+3]&&f[k+4][l+4]) t=true;
            	for (int k=0;k<6;k++)
            	    for (int l=0;l<6;l++)
            	        if (f[k+4][l]&&f[k+3][l+1]&&f[k+2][l+2]&&f[k+1][l+3]&&f[k][l+4]) t=true;
    	        if (t) ans=true;
    	        f[i][j]=false;
    	    }
    if (ans) printf("YES\n"); else printf("NO\n");
    return 0;
}