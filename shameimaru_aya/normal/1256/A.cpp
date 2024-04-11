#include<bits/stdc++.h> 
using namespace std;
int a , b , n , S , T;
int main()
{
	cin >> T;
	while(T--)
	{
		scanf("%d%d%d%d" , &a , &b , &n , &S);
		int qwq = S / n;
		S -= min(qwq , a) * n;
		if(b >= S) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}