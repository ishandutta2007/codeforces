#include<cstdio>
using namespace std;

const int Mod=1e9+7;
int x,y,n,Ans;

int main()
{
	scanf("%d%d",&x,&y);
	scanf("%d",&n);
	switch (n%6)
	{
		case 1:{Ans=x;break;}
		case 2:{Ans=y;break;}
		case 3:{Ans=y-x;break;}
		case 4:{Ans=-x;break;}
		case 5:{Ans=-y;break;}
		case 0:Ans=x-y;
	}
	printf("%d\n",(Ans%Mod+Mod)%Mod);
}