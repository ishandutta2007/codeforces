#include<bits/stdc++.h>
using namespace std;
int a[212345];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) a[i] = 0;
		int cur = 0;
		int pos = 1;
		for(int i = 1; i <= n; i++)
		{
			if(a[i]) continue;
			cout << "? " << i << endl;
			int j;
			cin >> j;
			while(true)
			{
				cout << "? " << i << endl;
				int x;
				cin >> x;
				
				a[j] = x;
				j = x;
				if(a[j]) break;
			}
		}
		cout << "!";
		for(int i = 1; i <= n; i++)
		{
			cout << " " << a[i];
		} 
		cout << endl;
	}
	return 0;
}