#include <iostream>
#include <string>
#include <cmath>
#define ll long long

using namespace std;
double log2(int x)
{
	return log((double)x) / log((double)2);	
} 
int main()
{
	int n;
	cin >> n;
	n -= 1;
	string a[5];
	a[0] = "Sheldon";
	a[1] = "Leonard";
	a[2] = "Penny";
	a[3] = "Rajesh";
  a[4] = "Howard";
  int p = 0;
  for (; 5 * pow(2.0, p) <= n; ++p)
  	n -= 5 * pow(2.0, p);                                      
	cout << a[(int)(n / pow(2.0, p))];	     
}