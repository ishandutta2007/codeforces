#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
using namespace std;
char inp[maxn], otp[maxn];
bool check(char a)
{
	return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y');
}
int main()
{
	int l = 0;
	scanf("%d", &l);
	scanf("%s", inp);
//	l = strlen(inp);
	while(1)
	{
		bool flag = 0;
		for(int i = 0; i < l - 1; i++)
		{
			if(check(inp[i]) && check(inp[i + 1]))
			{
				for(int j = i + 1; j < l - 1; j++)
					inp[j] = inp[j + 1];
				flag = 1;
				break;
			}
		}
		if(!flag) break;
		l--;	
	} 
	for(int i = 0; i < l; i++)
		printf("%c", inp[i]);
	printf("\n");
	return 0;
 }