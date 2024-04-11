#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int N;
string str[1100];
int nstr;
int sum[1100];
int lval[1100];
string xv[1100];
int vv[1100];

int main()
{
	for (int i = 0; i < 1100; i++)
	{
		sum[i] = 0;
		lval[i] = 0;
	}
	nstr = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string x;
		int v;
		cin >> x >> v;
		xv[i] = x;
		vv[i] = v;
		
		for (int j = 0; j <= nstr; j++)
		{
			if (j == nstr)
			{
				nstr++;
				str[nstr-1] = x;
				lval[nstr-1] = i;
				sum[nstr-1] = v;
				break;
			}
			if (str[j] == x)
			{
				lval[j] = i;
				sum[j] += v;
				break;
			}
		}
	}
	
	string winner;
	int v = -10000000, nl;
	for (int i = 0; i < nstr; i++)
	{
		if (sum[i] > v)
		{
			v = sum[i];
			winner = str[i];
			int s = 0;
			int j;
			for (j = 0; j < N; j++)
				if (str[i] == xv[j])
				{
					s += vv[j];
					if (s >= v)
						break;
				}
			nl = j;
		}
		else if (sum[i] == v)
		{
			int s = 0;
			int j;
			for (j = 0; j < N; j++)
				if (str[i] == xv[j])
				{
					s += vv[j];
					if (s >= v)
						break;
				}
			if (j < nl)
			{
				nl = j;
				winner = str[i];
			}
		}
	}
	cout << winner << "\n";
	return 0;
}