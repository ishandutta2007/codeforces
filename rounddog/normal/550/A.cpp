#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 100020

using namespace std;
char s[maxn];
int k,l,n;
bool f;

int main()
{
	scanf("%s",s);
	n=strlen(s);
	f=false;
	k=0;
	while (k<n-1&&s[k]!='A'||s[k+1]!='B') k++;
	if (k<n-1){
	    k+=2;
	   	while (k<n-1&&s[k]!='B'||s[k+1]!='A') k++;
	    if (k<n-1) f=true;
	}
	k=0;
	while (k<n-1&&s[k]!='B'||s[k+1]!='A') k++;
	if (k<n-1){
	    k+=2;
	   	while (k<n-1&&s[k]!='A'||s[k+1]!='B') k++;
	    if (k<n-1) f=true;
	}
	if (f) printf("YES\n"); else printf("NO\n");
	return 0;
}