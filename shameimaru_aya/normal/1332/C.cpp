#include<bits/stdc++.h>
using namespace std;
int T , n , k , a[30] , maxx , ans;
string s;
int main()
{
	cin.tie(0) , cout.tie(0);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &k);
		cin >> s;
		ans = 0;
		for(int i = 1 ; i <= (k + 1) / 2 ; i++ )
		{
			memset(a , 0 , sizeof(a)); maxx = 0;
			for(int j = 1 ; j <= n / k ; j++ )
			{
				int qwq = s[i + (j - 1) * k - 1] - 'a';
				a[qwq]++;
				maxx = max(maxx , a[qwq]);
				if(k - i == i - 1) continue;
				qwq = s[k - i + (j - 1) * k] - 'a';
				a[qwq]++;
				maxx = max(maxx , a[qwq]);
			}
			ans += 2 * n / k - maxx;
			if(k - i == i - 1) ans -= n / k;
//			cerr << n / k - maxx << '\n';
		}
		printf("%d\n" , ans);
	}
    return 0;
}