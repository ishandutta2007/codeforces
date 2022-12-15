#include<bits/stdc++.h>

using namespace std;

const int N = 1007;

vector<int> res;
int a[N];
int b[N];
int n;

bool check(int x)
{
	for(int i = 0; i < n-x; i++)
		if(b[i] != b[i+x])
			return 0;

	return 1;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	b[0] = a[0];
	for(int i = 1; i < n; i++)
		b[i] = a[i] - a[i-1];

	for(int i = 1; i <= n; i++)
		if(check(i))
			res.push_back(i);

	cout << res.size() << "\n";

	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}