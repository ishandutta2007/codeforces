#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int wt[1000005];
	string a, b;
	cin >> n;
	cin >> a >> b;
	for(int i = 0; i < n; i++)
	{
	    if(a[i] == b[i]) wt[i] = 0;
	    else if(a[i] == '1') wt[i] = 1;
	    else wt[i] = -1;
	}
	int ans = 0;
	int i = 0;
	for(int i = 0; i < n; i++)
	{
	    if(wt[i] != 0)
	    {
	        if(i < n - 1 && wt[i] + wt[i + 1] == 0) i++;
	        ans++;
	    }
	}
	cout << ans;
}