#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int MAXT = 24;

int N;
int l1[MAXT];
int l2[MAXT][MAXT];
int l3[MAXT][MAXT][MAXT];

int c[17000];

int ctot;
int cval, cres;

int main()
{
	c[1] = 0;
	for (int i = 2; i < 17000; i *= 2)
		c[i] = c[i/2] + 1;
	
	for (int i = 0; i < MAXT; i++)
	{
		l1[i] = 0;
		for (int j = 0; j < MAXT; j++)
		{
			l2[i][j] = 0;
			for (int k = 0; k < MAXT; k++)
				l3[i][j][k] = 0;
		}
	}
	
	ios_base::sync_with_stdio (0);
	
	cin >> N;
	int t[3];
	for (int i = 0; i < N; i++)
	{
		char ch;
		for (int j = 0; j < 3; j++)
		{
			cin >> ch;
			t[j] = (ch - 'a');
		}
		
		sort (t, t + 3);
		
		if (t[0] == t[2])
			l1[t[0]]++;
		else if (t[0] == t[1] || t[1] == t[2])
		{
			l2[t[0]][t[2]]++;
			l2[t[2]][t[0]]++;
		}
		else
		{
			l3[t[0]][t[1]][t[2]]++;
			l3[t[0]][t[2]][t[1]]++;
			l3[t[1]][t[0]][t[2]]++;
			l3[t[1]][t[2]][t[0]]++;
			l3[t[2]][t[0]][t[1]]++;
			l3[t[2]][t[1]][t[0]]++;
		}
	}
	
	cval = (1 << 24) - 1;
	cres = 0;
	ctot = 0;
	int ans = 0;
	
	for (int i = 1; i < 24; i++)
		for (int j = i + 1; j < 24; j++)
			ctot += l3[0][i][j];
	
	for (int i = 1; i < (1 << 24); i++)
	{
		/*if (cres)
		{
			cout << cval << " " << cres << "\n";
		}*/
		ans ^= (cres * cres);
		
		int b = i & -i;
		if (b > 16384)
			b = 14 + c[b / 16384];
		else
			b = c[b];
		
		int nval = l1[b], ntot = 0;
		for (int j = 0; j < 24; j++)
			if (cval & (1 << j))
				nval += l2[b][j];
		
		if (b == 0)
			nval += ctot;
		else
		{
			for (int j = 0; j < 24; j++)
				if (cval & (1 << j))
					for (int k = j + 1; k < 24; k++)
						if (cval & (1 << k))
						 	nval += l3[b][j][k];
			
			for (int j = 1; j < 24; j++)
				if (cval & (1 << j))
					ntot += l3[0][b][j];
		}
		
		if (cval & (1 << b))
		{
			cres += nval;
			ctot -= ntot;
		}
		else
		{
			cres -= nval;
			ctot += ntot;
		}
		cval ^= (1 << b);
		
		//if (i <= 5)
		//	cout << i << " " << " " << ((1 << 24) - 1 - cval) << " " << ctot << " " << cres << endl;
	}
	ans ^= (cres * cres);
	
	cout << ans << "\n";
	return 0;
}