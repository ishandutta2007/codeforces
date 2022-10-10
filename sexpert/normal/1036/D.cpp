#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	vector<int> a, b;
	int ans = 0;
	long long asum = 0, bsum = 0;
	int aind = 0, bind = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
	    int x;
	    cin >> x;
	    a.push_back(x);
	    asum+=x;
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
	    int x;
	    cin >> x;
	    b.push_back(x);
	    bsum+=x;
	}
	if(asum != bsum) ans = -1;
	else
	{
	    ans = 1;
	    bool starting = true;
    	while(aind + bind < n + m)
    	{
    	    if(starting)
    	    {
    	        asum += a[aind];
    	        aind++;
    	        starting = false;
    	    }
    	    else
    	    {
    	        if(asum < bsum)
    	        {
    	            asum += a[aind];
    	            aind++;
    	        }
    	        else if(bsum < asum)
    	        {
    	            bsum += b[bind];
    	            bind++;
    	        }
    	        else
    	        {
    	            ans++;
    	            asum = bsum = 0;
    	            starting = true;
    	        }
    	    }
    	}
	}
	if(ans == 0) cout << 0 << endl;
	else cout << ans << endl;
}