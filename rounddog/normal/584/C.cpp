#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#define maxn 100020

using namespace std;

int n,t,b[maxn],cnt,p,q;
char s[maxn],s1[maxn],s2[maxn];

char chose(char x,char y)
{
	if (x!='a'&&y!='a') return 'a';
	else if (x!='b'&&y!='b') return 'b';
	else return 'c';
}

int main()
{
	scanf("%d%d",&n,&t);
	scanf("%s",s1);
	scanf("%s",s2);
	cnt=0;p=0;q=0;
	for (int i=0;i<n;i++)
	    if (s1[i]!=s2[i]) cnt++;
	    //printf("%d\n",(cnt+1)/2);
	if (t<(cnt+1)/2){
		printf("-1\n");
		return 0;
	}
	if (t<=cnt){
		for (int i=0;i<n;i++)
		{
			if (s1[i]==s2[i]) s[i]=s1[i];
			else{
				p++;
				if (p<=2*t-cnt) s[i]=chose(s1[i],s2[i]);
				else if (p%2==1) s[i]=s1[i]; else s[i]=s2[i];
			}
		}
	}
	else{
		for (int i=0;i<n;i++)
		{
			if (s1[i]==s2[i]){
				q++;
				if (q<=t-cnt) s[i]=chose(s1[i],s1[i]); else s[i]=s1[i];
			}
			else{
				p++;
				s[i]=chose(s1[i],s2[i]);
			}
		}
	}
	printf("%s",s);
	return 0;
}