#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	long long x, y, k;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
	    cin >> x >> y >> k;
	    x = abs(x);
	    y = abs(y);
	    if(max(x, y) > k) cout << -1 << endl;
	    else
	    {
	        long long ans;
	        if(x%2 == y%2)
	        {
	            if(x%2 == k%2) ans = k;
	            else ans = k - 2;
	        }
	        else ans = k - 1;
	        cout << ans << endl;
	    }
	}
}