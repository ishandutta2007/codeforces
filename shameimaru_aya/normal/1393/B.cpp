#include<bits/stdc++.h>
using namespace std;
int n , m , a , t[110000] , tot8 , tot6 , tot4 , tot2;
string s;
int main()
{
	cin.tie(0); cout.tie(0);
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ )
	{
		scanf("%d" , &a);
		t[a]++;
		if(t[a] == 8)
		{
			tot8++;
		}
		if(t[a] == 6)
		{
			tot6++;
		}
		if(t[a] == 4) 
		{
			tot4++;
		}
		if(t[a] == 2) tot2++;
	}
	scanf("%d" , &m);
	while(m--)
	{
		cin >> s; scanf("%d" , &a);
		if(s == "+")
		{
			t[a]++;
			if(t[a] == 8)
			{
				tot8++;
			}
			if(t[a] == 6)
			{
				tot6++;
			}
			if(t[a] == 4) 
			{
				tot4++;
			}
			if(t[a] == 2) tot2++;
		}
		else
		{
			t[a]--;
			if(t[a] == 7)
			{
				tot8--;
			}
			if(t[a] == 5)
			{
				tot6--;
			}
			if(t[a] == 3) 
			{
				tot4--;
			}
			if(t[a] == 1) tot2--;
		}
//		cerr << tot2 << ' ' << tot4 << ' ' << tot6 << endl;
		if((tot6 && tot2 >= 2) || 
		   (tot4 && tot2 >= 3) || 
		   (tot4 >= 2) ||
		   tot8)
		printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}