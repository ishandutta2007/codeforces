#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a, b;
	for(int i = 0; i < n; i++)
	{
	    int x;
	    cin >> x;
	    a.push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
	    int x;
	    cin >> x;
	    b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int inda = n - 1, indb = n - 1;
	bool aTurn = true;
	long long diff = 0;
	for(int i = 0; i < 2*n; i++)
	{
	    if(aTurn)
	    {
	        if(inda == -1) indb--;
	        else if(indb == -1 || a[inda] > b[indb])
	        {
	            diff += a[inda];
	            inda--;
	        }
	        else indb--;
	    }
	    else
	    {
	        if(indb == -1) inda--;
	        else if(inda == -1 || b[indb] > a[inda])
	        {
	            diff -= b[indb];
	            indb--;
	        }
	        else inda--;
	    }
	    aTurn = !aTurn;
	}
	cout << diff << "\n";
}