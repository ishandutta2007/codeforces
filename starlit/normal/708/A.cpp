#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,i,j;
char S[N];
int main()
{
	scanf("%s",S);n=strlen(S);
    for(i=0;i<n-1;i++)
    if(S[i]^'a')break;
    for(j=i;j<n-1;j++)
    if(S[j+1]=='a')break;
    for(int k=i;k<=j;k++)
    if(S[k]=='a')S[k]='z';
    else S[k]--;
    puts(S);
}