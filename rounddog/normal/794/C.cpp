#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 300040

using namespace std;

char s[maxn],t[maxn];
int n,m,p,q,f;
bool g; 

bool cmp(char x,char y)
{
	return x<y;
}

int main()
{
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	sort(s,s+n,cmp);
	sort(t,t+n,cmp);
	p=0;q=n-1;f=0;g=true;
	for (int i=0;i<n;i++)
	{
		if (g&&s[p]>=t[q]){
		    if ((n-i)%2==0) f=1; else g=false;
		}
	    if (i%2==f) printf("%c",s[p++]);
	    else printf("%c",t[q--]);
	}
	printf("\n");
	return 0;
}