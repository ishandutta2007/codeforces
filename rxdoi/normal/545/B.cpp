#include<cstdio>
#include<cctype>
#include<string>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

string A,B;
int n,cnt,t;

int main()
{
	cin>>A>>B;n=A.length();
	For(i,0,n) cnt+=(A[i]!=B[i]);
	if (cnt&1) return puts("impossible"),0;
	For(i,0,n)
		if (A[i]!=B[i]) putchar(t?A[i]:B[i]),t^=1;else putchar(A[i]);
	puts("");
}