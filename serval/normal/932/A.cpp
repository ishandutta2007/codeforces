#include <cstdio>
using namespace std;
char str[10005];
int len,i;
int main()
{
	scanf("%s",str+1);
	for (len=1;str[len+1];len++);
	for (i=len+1;i<=len+len;i++)
		str[i]=str[len+len-i+1];
	str[len+len+1]=0;
	printf("%s\n",str+1);
	return 0;
}