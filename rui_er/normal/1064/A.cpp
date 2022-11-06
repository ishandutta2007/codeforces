//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main()
{
	cin>>a>>b>>c;
	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	if(a > c) swap(a, c);
	if(a + b > c) cout<<0<<endl;
	else cout<<c-a-b+1<<endl;
	return 0;
}