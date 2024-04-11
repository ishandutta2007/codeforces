#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string A;
int Ans,s[5];

int main()
{
	for (int i=1;i<=4;i++) scanf("%d",&s[i]);
	cin>>A;
	for (int i=0;i<A.length();i++) Ans+=s[A[i]-'0'];
	printf("%d\n",Ans);
}