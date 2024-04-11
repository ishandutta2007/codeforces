#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
char c[105][105];
int main()
{
	std::ios::sync_with_stdio(false);
	int a, b, cc, d;
	cin >> a >> b >> cc >> d;
	for(int i = 1; i <= 25; i ++)
		c[i][1] = 'A';
	int x = 1, y = 2;
	bool asd = 0;
	int cnt = 0;
	while(b > 1)
	{
		cnt ++;
		if(cnt == 3)
		{
			cnt = 0;
			for(int i = x; i < x + 25; i ++)
				c[i][y] = 'A';
			y ++;
			continue;
		}
		c[x][y] = c[x + 24][y] = 'A';
		for(int i = x + 1; i < x + 24; i ++)
		{
			if((i - x) % 4 == 0)
				c[i][y] = 'A';
			else if(b > 1 && asd == 0 && ((i - x) & 1))
			{
				c[i][y] = 'B';
				b --;
			}
			else if(b > 1 && asd == 1 && (~(i - x) & 1))
			{
				c[i][y] = 'B';
				b --;
			}
			else
				c[i][y] = 'A';
		}
		y ++;
		asd ^= 1;
	}
	for(int i = x; i < x + 25; i ++)
		c[i][y] = 'A';
	y ++;
	for(int i = x; i < x + 25; i ++)
		c[i][y] = 'B';
	y ++;
	asd = 0;
	cnt = 0;
	while(a > 1)
	{
		cnt ++;
		if(cnt == 3)
		{
			cnt = 0;
			for(int i = x; i < x + 25; i ++)
				c[i][y] = 'B';
			y ++;
			continue;
		}
		c[x][y] = c[x + 24][y] = 'B';
		for(int i = x + 1; i < x + 24; i ++)
		{
			if((i - x) % 4 ==0)
				c[i][y] = 'B';
			else if(a > 1 && asd == 0 && ((i - x) & 1))
			{
				c[i][y] = 'A';
				a --;
			}
			else if(a > 1 && asd == 1 && (~(i - x) & 1))
			{
				c[i][y] = 'A';
				a --;
			}
			else
				c[i][y] = 'B';
		}
		y ++;
		asd ^= 1;
	}
	for(int i = x; i < x + 25; i ++)
		c[i][y] = 'B';
	y ++;
	x += 25;
	int yy = y;
	y = 2;
	for(int i = x; i < x + 25; i ++)
		c[i][1] = 'C';
	asd = 0;
	cnt = 0;
	while(d > 1)
	{
		cnt ++;
		if(cnt == 3)
		{
			cnt = 0;
			for(int i = x; i < x + 25; i ++)
				c[i][y] = 'C';
			y ++;
			continue;
		}
		c[x][y] = c[x + 24][y] = 'C';
		for(int i = x + 1; i < x + 24; i ++)
		{
			if((i - x) % 4 == 0)
				c[i][y] = 'C';
			else if(d > 1 && asd == 0 && ((i - x) & 1))
			{
				c[i][y] = 'D';
				d --;
			}
			else if(d > 1 && asd == 1 && (~(i - x) & 1))
			{
				c[i][y] = 'D';
				d --;
			}
			else
				c[i][y] = 'C';
		}
		y ++;
		asd ^= 1;
	}
	for(int i = x; i < x + 25; i ++)
		c[i][y] = 'C';
	y ++;
	for(int i = x; i < x + 25; i ++)
		c[i][y] = 'D';
	y ++;
	asd = 0;
	cnt = 0;
	while(cc > 1)
	{
		cnt ++;
		if(cnt == 3)
		{
			cnt = 0;
			for(int i = x; i < x + 25; i ++)
				c[i][y] = 'D';
			y ++;
			continue;
		}
		c[x][y] = c[x + 24][y] = 'D';
		for(int i = x + 1; i < x + 24; i ++)
		{
			if((i - x) % 4 == 0)
				c[i][y] = 'D';
			else if(cc > 1 && asd == 0 && ((i - x) & 1))
			{
				c[i][y] = 'C';
				cc --;
			}
			else if(cc > 1 && asd == 1 && (~(i - x) & 1))
			{
				c[i][y] = 'C';
				cc --;
			}
			else
				c[i][y] = 'D';
		}
		y ++;
		asd ^= 1;
	}
	for(int i = x; i < x + 25; i ++)
		c[i][y] = 'D';
	y ++;
	if(y < yy)
		for(int i = x; i < x + 25; i ++)
			for(int j = y; j < yy; j ++)
				c[i][j] = 'D';
	if(yy < y)
		for(int i = 1; i < 26; i ++)
			for(int j = yy; j < y; j ++)
				c[i][j] = 'B';
	int n = 50, m = max(y, yy) - 1;
	cout << n << " " << m << endl;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
			cout << c[i][j];
		cout << endl;
	}
	
	return 0;
}