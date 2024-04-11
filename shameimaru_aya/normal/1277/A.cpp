#include<bits/stdc++.h>
using namespace std;
int T , n , ans , v , a , s;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		a = s = ans = v = 0;
		int qwq = n;
		while(qwq)
		{
			a = a * 10 + 1;
			qwq /= 10;
			v++;
		}
		ans = (v - 1) * 9;
		for(int i = 1 ; i <= 9 ; i++ )
		{
			s += a;
			if(n >= s) ans++;
			else break;
		}
		printf("%d\n" , ans);
	}
	
	return 0;
}