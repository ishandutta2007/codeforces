#include<bits/stdc++.h>
using namespace std;
int T , n;
string s;
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> s;
		for(int i = 1 ; i <= n ; i++ )
		{
			printf("%c" , s[2 * i - 2]);
		}
		printf("\n");
	}
    return 0;
}