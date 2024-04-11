#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	int colors[25];
	for(int i = 0; i < n; i++)
	{
	    cin >> colors[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
	    if(colors[i] + colors[n - 1 - i] == 1)
	    {
	        cout << -1 << endl;
	        return 0;
	    }
	    if(colors[i] == 0 && colors[n - 1 - i] == 2) ans += a;
	    if(colors[i] == 1 && colors[n - 1 - i] == 2) ans += b;
	    if(colors[i] == 2 && colors[n - 1 - i] == 2)
	    {
	        ans += 2*min(a, b);
	        if(i == n - 1 - i) ans -= min(a, b);
	        colors[i] = 3;
	    }
	}
	cout << ans << endl;
}