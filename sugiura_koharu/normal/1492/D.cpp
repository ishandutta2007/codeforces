#include <iostream>
using namespace std;
string a,b;
int main(int argc, char** argv) {
	int x,y,k;
	cin >> x >> y >> k;
	if(!x)
	{
		if(k) puts("No");
		else
		{
			puts("Yes");
			for(int i=1;i<=y;i++) cout << 1;
			puts("");
			for(int i=1;i<=y;i++) cout << 1;
		}
		return 0;
	}
	if(y==1)
	{
		if(k) puts("No");
		else
		{
			puts("Yes");
			for(int i=0;i<=x;i++) cout << (!i);
			puts("");
			for(int i=0;i<=x;i++) cout << (!i);
		}
		return 0;
	}
	if(k>x+y-2)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=x+y;i++) a+='0';
	b=a;
	a[0]=b[0]='1',b[x+y-1]='1',a[x+y-k-1]='1';
	int t=x+y;
	y-=2;
	for(int i=0;i<=t;i++)
		if(a[i]=='0'&&b[i]=='0'&&y) --y,a[i]=b[i]='1';
	cout << a << "\n" << b;
	return 0;
}