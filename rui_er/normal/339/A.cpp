#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	char c;
	int a[100001];
	int last = 0;
	while(cin>>c)
		if(c >= '0' && c <= '9')
			a[last++] = c - '0';
	sort(a, a+last);
	for(int i=0;i<last-1;i++) cout<<a[i]<<"+";
	cout<<a[last-1]<<endl;
	return 0;
}