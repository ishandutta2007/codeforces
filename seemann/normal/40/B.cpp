#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;



int main()
{
	int n, m, x;
	cin >> n >> m >> x ;
	if (x > min(n, m) / 2 + min(n,m) % 2){
		cout << 0;
		return 0;
	}
	x--;
	n -=2*x;
	m-=2*x;
	int w = (m + n)*2 - 4;
	if ((m == 1)&&(n==1)) w = 2;

       	cout << (w / 2);	
	return 0;
}