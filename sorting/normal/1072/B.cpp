#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int a[N], b[N];
int t[N];

int main ()
{
	int n;

	cin >> n;

	for(int i = 0; i < n-1; i++)
		cin >> a[i];
	for(int i = 0; i < n-1; i++)
		cin >> b[i];

	for(int i = 0; i <= 3; i++)
	{
		t[0] = i;

		bool tr = true;

		for(int j = 0; j < n-1; j++)
		{
			tr = false;
			//cout << t[j] << " " << j <<  endl;

			for(int k = 0; k <= 3; k++)
				if(((k | t[j]) == a[j]) && ((k & t[j]) == b[j]))
				{
					t[j+1] = k;
					//cout << k << endl;
					tr = true;
					break;
				}
			if(tr == false)
				break;
		}

		if(tr)
		{
			cout << "YES\n";

			for(int i = 0; i < n; i++)
				cout << t[i] << " ";
			cout << "\n";

			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}