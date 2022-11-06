#include<iostream>
#define MAXN 505

using namespace std;

int t;
int n;
int a[MAXN];

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		    cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != i)
			{
				for(int j = i; j <= n; j++)
				{
					if(a[j] == i)
					{
						for(int s = 1; s < i; s++)
						    cout << s << " ";
						for(int s = j; s >= i; s--)
						    cout << a[s] << " ";
						for(int s = j+1; s <= n; s++)
						    cout << a[s] << " ";
						cout << endl; 
					}
				}
				break;	
			}
			if(i == n)
			{
				for(int j = 1; j <= n; j++)
				    cout << j << " ";
				cout << endl; 
			}
		}	
	}
	
	return 0;
}