#include <bits/stdc++.h>
using namespace std;

#define O ^
#define A &
#define X |

int main()
{
	int a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, d1;
	cin >> a1 >> a2 >> a3 >> a4;
	b1 = a1 O a2;
	b2 = a3 X a4;
	b3 = a2 A a3;
	b4 = a1 O a4;
	c1 = b1 A b2;
	c2 = b3 X b4;
	d1 = c1 O c2;
	cout << d1 << endl;
}