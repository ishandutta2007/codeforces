#include<bits/stdc++.h>
using namespace std;
long long a[3];
int main()
{
	for(int i = 0; i < 3; i++) cin >> a[i];
	cout << "First" << endl;
	cout << "10000000000" << endl;
	int x;
	cin >> x;
	if(x == 0) return 0;
	x--;
	a[x] += 10000000000ll;
	long long need = 0;
	for(int i = 0; i < 3; i++)
	{
		if(i == x) need += 2 * a[i];
		else need -= a[i];
	}
	cout << need << endl;
	cin >> x;
	if(x == 0) return 0;
	x--;
	a[x] += need;
	need = 0;
	for(int i = 0; i < 3; i++)
	{
		if(i == x) need += 2 * a[i];
		else need -= a[i];
	}
	need /= 3;
	cout << need << endl;
	cin >> x;
	if(x == 0) return 0;
	x--;
	
	
	
	return 0;
}