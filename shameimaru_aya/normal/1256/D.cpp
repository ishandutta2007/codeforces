#include<bits/stdc++.h> 
using namespace std;
char s[1100000];
long long T , zero[1100000] , n , k , ans[1100000] , tot;
int main()
{
	cin >> T;
	while(T--)
	{
		scanf("%lld%lld%s" , &n , &k , s + 1);
		tot = 0;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(s[i] - '0' == 0) zero[++tot] = i;
			ans[i] = 0;
		}
		for(int i = 1 ; i <= tot ; i++ )
		{
			int qwq = min(k , zero[i] - i);
//			cerr << k << " " << qwq << endl;
			k -= qwq;
			ans[zero[i] - qwq] = 1;
//			cerr << zero[i] - qwq << endl;
		}
		for(int i = 1 ; i <= n ; i++ )
		{
			printf("%d" , (ans[i] ^ 1));
		}
		printf("\n");
	}
	return 0;
}