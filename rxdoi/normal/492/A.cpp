#include<cstdio>
using namespace std;

int x;

int main()
{
	scanf("%d",&x);
	for (int cnt=0,tmp=0,i=1;;tmp+=i,i++,cnt+=tmp)
		if (cnt>x) return printf("%d\n",i-2),0;
}