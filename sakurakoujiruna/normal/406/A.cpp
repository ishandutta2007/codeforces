#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1011;

int s[N];

int main()
{
	//ios :: sync_with_stdio(false);

	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			int x;
			//cin >> x;
			scanf("%d", &x);
			if(i == j)
				sum ^= x;
		}
	}
	
	int q;
	cin >> q;
	while(q --)
	{
		int t;
		//cin >> t;
		scanf("%d", &t);
		if(t == 3)
			cout << sum;
		else
		{
			//cin >> t;
			scanf("%d", &t);
			//if(n & 1)
				sum ^= 1;
		}
	}

	return 0;
}