#include <stdio.h>
#include <algorithm>
#define T char
inline void swap(T &x, T &y)//!
{
	T t = x;
	x = y, y = t;
}
#undef T
#define T int
inline T read()
{
	T num = 0; int f = 1; char c = getchar();
	while (c < 48 || c > 57){ if (c == '-')f = -1; c = getchar(); }
	while (c >= 48 && c <= 57)num = num * 10 + (c ^ 48), c = getchar();
	return num * f;
}
#undef T
struct IOI{
	int c,n;
	bool operator<( IOI b)const
	{
		return c==b.c?n<b.n:c<b.c;
	}
}AK[400005];
char a[400005];
inline int f(IOI a,IOI b)
{return a.n<b.n;}
int main()
{
	int n=read(),m=read(),q=0;
	scanf("%s",a);
	for(int i=0;i<n;i++)AK[i]={a[i],i};
	std::sort(AK,AK+n);
/*	for(int i=n-1;i>=0;i--)
	{
		if(a[i]=='z')q++;
		else break;
	}
	if(n-m<q)
	{
		while(q>1)q--,putchar('z');puts("");
		return 0;
	}*/
	//auto f=[](IOI a,IOI b){return a.n<b.n;}
	std::sort(AK+m,AK+n,f);
	for(int i=m;i<n;i++)putchar(AK[i].c);
	//printf("%s\n",a+1);
	return 0;
}