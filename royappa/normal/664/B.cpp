#include <bits/stdc++.h>

using namespace std;


typedef long long LL;


int main()
{
	string s;
	int numPlus = 1, numMinus = 0, n;
	cin >> s;
	vector<string> v;
	v.push_back(s);
	while (s != "=")
	{
		if (s == "+") numPlus++;
		else if (s == "-") numMinus++;
		cin >> s;
		v.push_back(s);
	}
	cin >> s;
	v.push_back(s);
	n = atoi(s.c_str());
	vector<int> pval, mval;
	bool found;
	if (numMinus == 0)
	{
		if (numPlus > n)
		{
			found = false;
		}
		else
		{
			for (int i = 1; i <= numPlus-1; i++)
				pval.push_back(n/numPlus);
			pval.push_back(n-(numPlus-1)*(n/numPlus));
			found = true;
		}
	}
	else
	{
		found = false;
		for (int x = 1; x <= n*numPlus; x++)
		{
			int y = x-n;
			if (x < numPlus || x > numPlus*n || y < numMinus || y > numMinus*n) continue;
			found = true; //cout << x << "-" << y << "=" << n << endl;
			for (int i = 1; i <= numPlus; i++)
				pval.push_back(x/numPlus);
			int m = pval.size();
			for (int i = 1; i <= x%numPlus; i++)
				pval[m-i]++;
			for (int i = 1; i <= numMinus; i++)
				mval.push_back(y/numMinus);
			m = mval.size();
			for (int i = 1; i <= y%numMinus; i++)
				mval[m-i]++;
			//cout << mval.size() << endl;
			break;
		}
	}
	if (!found)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << "Possible" << endl;
		int pp = 0, pm = 0;
		int t = 1;
		for (int i = 0; i < v.size(); i++)
		{
			string z = v[i];
			if (z == "?")
				cout << (i != 0 ? " " : "") << (t == 1 ? pval[pp++] : mval[pm++]);
			else if (z == "+")
				t = 1, cout << " +";
			else if (z == "-")
				t = 0, cout << " -";
			else if (z == "=")
				cout << " =";
			else
				cout << " " << n;
		}
		cout << endl;
	}
	exit(0);
}