#include<bits/stdc++.h>
using namespace std;
int T , n , tot , ans[220000];
string a , b;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		cin >> a >> b;
		a = a + '0' , b = b + '0';
		tot = 0;
		for(int i = 0 ; i < n ; i++ )
			if(a[i] != a[i + 1]) ans[++tot] = i + 1;
		for(int i = n - 1 ; i >= 0 ; i-- )
			if(b[i] != b[i + 1]) ans[++tot] = i + 1;
		printf("%d " , tot);
		for(int i = 1 ; i <= tot ; i++ ) printf("%d " , ans[i]);
		printf("\n");
	}
    return 0;
}
/*
*/