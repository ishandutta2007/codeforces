#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int MX = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		MX = max(MX, x);
	}
	if(MX == 0) cout << "EASY\n";
	else cout << "HARD\n";
}