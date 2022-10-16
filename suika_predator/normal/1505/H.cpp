#include<bits/stdc++.h>
using namespace std;
int a[23]={44,12,49,17,10,25,18,17,24,25,20},
b[23]={55,99,61,99,91,90,98,30,25,30,29};
int main()
{
	for(int i=0;i<11;i++)
	{
		cout<<(char)(a[i]+b[i]);
	}
	return 0;
}