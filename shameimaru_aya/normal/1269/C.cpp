#include<bits/stdc++.h>
using namespace std;
int n , k , flag , a[410000] , pl;
string s;
int main()
{
	scanf("%d%d" , &n , &k);
	cin >> s;
	pl = n;
	for(int i = 1 ; i <= k ; i++ )
	{
		a[i] = s[i - 1] - '0';
		for(int j = i + k ; j <= pl ; j += k )
		{
			if(s[j - 1] - '0' > a[i]) flag = -1;
			if(s[j - 1] - '0' < a[i]) flag = 1;
			if(s[j - 1] - '0' != a[i])
			{
				pl = j; 
				break;
			}
		}
//		cerr << flag << endl; 
	}
//	cerr << flag << endl;
	if(flag == -1)
	{
		int r = k;
		while(a[r] == 9) a[r--] = 0;
		a[r]++;
	}
	printf("%d\n" , n);
	for(int i = 1 ; i <= n ; i++ )
	{
		int aa = i % k;
		if(!aa) aa = k;
		printf("%d" , a[aa]);
	}
	return 0;
}