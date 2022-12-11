#include<cstdio>
#include<cstring>
using namespace std;

char s[1000+19];
int c,A[200],Ans;

int main()
{
	gets(s);
	for (int i=0;i<strlen(s);i++) A[s[i]]=1;
	for (int i='a';i<='z';i++) 
		if (A[i]) Ans++;
	printf("%d\n",Ans);
}