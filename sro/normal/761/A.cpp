#include <cstdio>
#include <iostream>
using namespace std;

int JISHU,OUSHU;

int main()
{
	scanf("%d %d",&JISHU,&OUSHU);
	if(JISHU==0&&OUSHU==0)return puts("NO"),0; 
	if((JISHU-OUSHU==1)||(JISHU==OUSHU)||(OUSHU-JISHU==1))puts("YES");
	else puts("NO");
	return 0;
}