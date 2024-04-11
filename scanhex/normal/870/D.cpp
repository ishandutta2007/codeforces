#include <bits/stdc++.h>

using namespace std;

bool deb = false;
int n;
vector<int> p, b;

void init()
{
	if (!deb)
		return;
	p.resize(n);
	for (auto& x : p)
		cin >> x;
	b.resize(n);
	for (int i = 0; i < n; ++i)
		b[p[i]] = i;
}

int get(int i, int j)
{
	if (deb)
		return p[i] ^ b[j];
	cout << "? " << i << ' ' << j << endl;
	int x;
	cin >> x;
	if (x == -1)
		exit(0);
	return x;
}
void ans(int cnt, vector<int> p)
{
	cout << "!\n";
	cout << cnt << endl;
	for (int x : p)
		cout << x << ' ';
	cout << endl;
}

int main()
{
	cin >> n;
	init();
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		a[i] = get(0, i);
	vector<int> x(n);
	for (int i = 0; i < n; ++i)
		x[i] = get(i, 0);
	int cnt = 0;
	vector<int> pans;
	for (int i = 0; i < n; ++i)
	{
		vector<int> b(n);
		for (int j = 0; j < n; ++j)
			b[j] = i ^ a[j];
		vector<int> arr(n);
		for (int i : b)
			if (i < n)
				++arr[i];
		if (count(arr.begin(), arr.end(), 1) != n)
			continue;
		vector<int> p(n);
		for (int j = 0; j < n; ++j)
			p[b[j]] = j;
		bool f = true;
		for (int j = 0; j < n; ++j)
			if ((p[j] ^ b[0]) != x[j])
				f = false;
		if (f)
			++cnt, pans = p;
	}
	ans(cnt, pans);
	/*
	for (int n = 4; n <= 4; ++n)
	{
		set<vector<int>> mem;
		for (int i = 0; i < n; ++i)
		{
			vector<int> kek;
			for (int j = 0; j < n; ++j)
			{
				kek.push_back(i ^ j);
			}
			for (int x : kek)
				cout << x << endl;
			cout << endl;
			sort(kek.begin(), kek.end());
			mem.insert(kek);
		}
		if (mem.size() != n)
			cout << n << endl;
	}
	*/
}