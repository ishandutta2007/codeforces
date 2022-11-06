//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, cnt; 

void f(int x)
{
	if(x > n) return;
	++cnt;
	f(10*x);
	f(10*x+1);
}

int main()
{
	cin>>n;
	f(1);
	cout<<cnt<<endl;
	return 0;
}