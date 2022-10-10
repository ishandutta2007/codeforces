#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, s;
	vector<int> a;
	cin >> n >> s;
	k = (n - 1)/2;
	for(int i = 0; i < n; i++)
	{
	    int aux;
	    cin >> aux;
	    a.push_back(aux);
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for(int i = 0; i < k; i++)
	{
	    if(a[i] > s) ans += (a[i] - s);
	}
	for(int i = k + 1; i < n; i++)
	{
	    if(a[i] < s) ans += (s - a[i]);
	}
	ans += abs(a[k] - s);
	cout << ans << "\n";
}