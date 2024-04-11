#include <bits/stdc++.h> 
using namespace std;
int T , n , a[500];
string las , noww;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; i++ )
		{
			scanf("%d" , &a[i]);
		}
		noww.clear();
		for(int i = 1 ; i <= 100 ; i++ ) noww = noww + 'a';
		for(int i = 1 ; i <= n ; i++ )
		{
			cout << noww << endl; las = noww; noww.clear();
			for(int j = 1 ; j <= a[i] ; j++ )
			{
				noww = noww + las[j - 1];
			}
			for(int j = a[i] + 1 ; j <= 100 ; j++ )
			{
				char c = las[j - 1] + 1;
				if(c > 'z') c = 'a';
				noww = noww + c;
			}
		}
		cout << noww << endl;
	}
	return 0;
}