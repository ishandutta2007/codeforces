#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	vector<int> skw;
	int offset = n%(2*k + 1);
	if(n <= 2*k + 1)
	{
	    cout << 1 << endl << (n + 1)/2 << endl;
	}
	else
	{
	    if(offset > k)
	    {
	        skw.push_back(offset - k);
	        ans++;
	        n -= offset;
	        int guy = k + offset + 1;
	        while(n > 0)
	        {
	            skw.push_back(guy);
	            guy += 2*k + 1;
	            n -= 2*k + 1;
	            ans++;
	        }
	    }
	    else if(offset == 0)
	    {
	        ans = n/(2*k + 1);
	        int guy = k + 1;
	        while(n > 0)
	        {
	            skw.push_back(guy);
	            guy += 2*k + 1;
	            n -= 2*k + 1;
	        }
	    }
	    else
	    {
	        ans += 2;
	        skw.push_back(1);
	        skw.push_back(n - offset + 1);
	        n -= offset;
	        n -= 2*k + 1;
	        int guy = 2*k + 2;
	        while(n > 0)
	        {
	            ans++;
	            skw.push_back(guy);
	            guy += 2*k + 1;
	            n -= 2*k + 1;
	        }
	    }
	    cout << ans << endl;
	    for(int s : skw) cout << s << " ";
	    cout << endl;
	}
}