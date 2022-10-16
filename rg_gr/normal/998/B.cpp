#include <stdio.h>
#include <queue>
inline long long read()
{
	char c=getchar(); long long f = 1, num = 0;
	while (c< 48||c>57){if (c == '-')f = -1; c = getchar();}
	while (c >= '0'&&c <= '9')num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return f*num;
}
std::priority_queue<int,std::vector<int>,std::greater<int> > q;
int a[105];
inline int abs(int x){return x>0?x:-x;}
int main()
{
	int n=read(),b=read();
	int c1=0,c2=0,f=0;
	for(int i=0;i<n;i++)
	{
		int x=read();
		if(f)q.push(abs(f-x));
		f=0;
		if(x&1)c1++;
		else c2++;
		if(c1==c2)f=x;
	}
	int ans=0;
	while(!q.empty())
	{
		int x=q.top();
	//	printf("%d %d\n",x,b);
		if(b>=x)ans++,b-=x;
		else break;
		q.pop();
	}
	printf("%d\n",ans);
	return 0;
}