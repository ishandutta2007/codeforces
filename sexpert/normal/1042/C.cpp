#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[200005];
	vector<int> pos, zero, neg;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] > 0) pos.push_back(i);
		if(a[i] == 0) zero.push_back(i);
		if(a[i] < 0) neg.push_back(i);
	}
	if(zero.size() == 0)
	{
		if(neg.size() % 2 == 0)
		{
			for(int i = 0; i < n - 1; i++) cout << 1 << " " << i + 1 << " " << i + 2 << endl;
		}
		else
		{
			int x = INT_MIN;
			int ind;
			for(int i = 0; i < n; i++)
			{
				if(a[i] > x && a[i] < 0)
				{
					ind = i;
					x = a[i];
				}
			}
			cout << 2 << " " << ind + 1 << endl;
			for(int i = 0; i < n - 1; i++)
			{
				if(i == ind) continue;
				if(i + 1 == ind)
				{
					if(i == n - 2) continue;
					else cout << 1 << " " << i + 1 << " " << i + 3 << endl;
				}
				else cout << 1 << " " << i + 1 << " " << i + 2 << endl;
			}
		}
	}
	else
	{
		if(neg.size() % 2 == 1)
		{

			int x = INT_MIN;
			int ind;
			for(int i = 0; i < n; i++)
			{
				if(a[i] > x && a[i] < 0)
				{
					ind = i;
					x = a[i];
				}
			}
			a[ind] = 0;
			zero.push_back(ind);
		}
		if(zero.size() == n)
		{
			for(int i = 0; i < n - 1; i++) cout << 1 << " " << i + 1 << " " << i + 2 << endl;
		}
		else
		{
			int lastZero = -1, lastNonZero = -1;
			for(int i = 0; i < n; i++)
			{
				if(a[i] == 0)
				{
					if(lastZero >= 0) cout << 1 << " " << lastZero + 1 << " " << i + 1 << endl;
					lastZero = i;
				}
				else
				{
					if(lastNonZero >= 0) cout << 1 << " " << lastNonZero + 1 << " " << i + 1 << endl;
					lastNonZero = i;
				}
			}
			cout << 2 << " " << lastZero + 1 << endl;
		}
	}
}