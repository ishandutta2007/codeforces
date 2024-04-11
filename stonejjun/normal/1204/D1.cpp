#include<bits/stdc++.h>
using namespace std;
char c[1010101];

int l[1010101];
int r[10101010];
int cnt1[10101010];
int cnt0[10101010];

int cnt;
int chk=-1;
int len;

int main()
{
    int i,j,k,m,n,c1=0,c0=0,cango=0;
    scanf("%s",&c);
    len=strlen(c);
    for(i=len-1;i>=0;i--)
    {
        if(c[i]=='0') c0++;
        else c1++;
        if(c1>c0) c[i]='0';
        if(c1>c0) c1=c0;
    }
    for(i=0;i<len;i++)
        printf("%c",c[i]);


}