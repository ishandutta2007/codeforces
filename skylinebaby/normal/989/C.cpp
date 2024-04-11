#include<bits/stdc++.h>
using namespace std;
char s[100][100];
int main()
{
	int a,b,c,d,p,q;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	printf("40 50\n");
	for(int i =  1;i<=10;i++) for(int j = 1;j<=50;j++)s[i][j]='A';
	for(int i = 11;i<=20;i++) for(int j = 1;j<=50;j++)s[i][j]='B';
	for(int i = 21;i<=30;i++) for(int j = 1;j<=50;j++)s[i][j]='C';
	for(int i = 31;i<=40;i++) for(int j = 1;j<=50;j++)s[i][j]='D';
	p=1;q=1;
	while(a>1)
	{
		s[20+p][q] = 'A';
		a--;
		if (q<45) q = q+2;
		else {p = p+2;q=1;} 
	}
	p=1;q=1;
	while(b>1)
	{
		s[30+p][q] = 'B';
		b--;
		if (q<45) q = q+2;
		else {p = p+2;q=1;} 
	}
	p=1;q=1;
	while(c>1)
	{
		s[p][q] = 'C';
		c--;
		if (q<45) q = q+2;
		else {p = p+2;q=1;} 
	}
	p=1;q=1;
	while(d>1)
	{
		s[10+p][q] = 'D';
		d--;
		if (q<45) q = q+2;
		else {p = p+2;q=1;} 
	}
	for(int i =  1;i<=40;i++) 
	{
		for(int j = 1;j<=50;j++)
		{
			printf("%c",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}