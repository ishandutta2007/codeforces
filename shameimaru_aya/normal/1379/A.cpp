#include <bits/stdc++.h> 
using namespace std;
int T , n , qwq;
string s , ss , t = "abacaba";
int count()
{
	int ans = 0;
	for(int i = 0 ; i <= n - 6 ; i++ )
	{
		int flag = 1;
		for(int j = 0 ; j < 7 ; j++ )
		{
			if(ss[i + j] != t[j])
			{
				flag = 0;
				break;
			}
		}
		ans += flag;
	}
	return ans;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		qwq = 0;
		scanf("%d" , &n); cin >> s;
		for(int i = 0 ; i <= n - 7 ; i++ )
		{
			ss = s;
			bool flag = 0;
			for(int j = 0 ; j < 7 ; j++ )
			{
				if(ss[i + j] != t[j] && ss[i + j] != '?')
				{
					flag = 1;
					break;
				}
				ss[i + j] = t[j];
			}
			if(!flag && count() == 1)
			{
				for(int j = 0 ; j < n ; j++ )
					if(ss[j] == '?') ss[j] = 'z';
				qwq = 1;
				break;
			}
		}
		if(!qwq) printf("No\n");
		else
		{
			printf("Yes\n");
			cout << ss << endl;
		}
	}
	
	return 0;
}