#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
using namespace std;
int main() 
{
	int n, m;
	cin >> n >> m;
	if ((n * m & 1) == 0)
		cout << ((n * m) >> 1) << endl;
	else
		cout << ((n * m - 1) >> 1) << endl;                
}