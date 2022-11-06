#include <iostream>
using namespace std;

bool a[101] = {true, false, false, true, false, false, true, true};

bool f(int x);

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		if(f(x)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

bool f(int x)
{
	if(a[x]) return a[x];
	else if(x < 7) return a[x];
	else return a[x] = f(x-3) or f(x-7);
}