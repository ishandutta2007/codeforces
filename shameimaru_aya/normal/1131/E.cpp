#include <bits/stdc++.h>
using namespace std;
int n , maxx[26][110000] , l[26][110000] , r[26][110000] , f[26];
char c[110000];
string s[110000];
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i++ ) 
	{
		scanf("%s" , c) , s[i] = c;
		for(int j = 0 ; j < 26 ; j++ )
		{
			for(int k = 0 ; k < s[i].size() ; k++ )
			{
				if(s[i][k] == j + 'a') l[j][i]++;
				else break; 
			}
			for(int k = (int)s[i].size() - 1 ; k >= 0 ; k-- )
			{
				if(s[i][k] == j + 'a') r[j][i]++;
				else break; 
			}
			int tot = 0;
			for(int k = 0 ; k < s[i].size() ; k++ )
			{
				if(s[i][k] == j + 'a') tot++;
				else maxx[j][i] = max(maxx[j][i] , tot) , tot = 0;
			}
			maxx[j][i] = max(maxx[j][i] , tot);
		}
	}
	for(int j = 0 ; j < 26 ; j++ ) 
		maxx[j][0] = maxx[j][1] , l[j][0] = l[j][1] , r[j][0] = r[j][1];
	for(int i = 2 ; i <= n ; i++ )
	{
		for(int j = 0 ; j < 26 ; j++ )
		{
			if(maxx[j][i] == s[i].size())
			{
				maxx[j][0] += (maxx[j][0] + 1) * maxx[j][i];
				l[j][0] += (l[j][0] + 1) * l[j][i];
				r[j][0] += (r[j][0] + 1) * r[j][i];
			}
			else
			{
				int qwq = maxx[j][0];
				maxx[j][0] = max((int)(!!maxx[j][0]) , maxx[j][i]);
				if(qwq) maxx[j][0] = max(maxx[j][0] , l[j][i] + r[j][i] + 1); 
				l[j][0] = l[j][i];
				r[j][0] = r[j][i];
			}
		}
	}
	for(int i = 0 ; i < 26 ; i++ ) maxx[0][0] = max(maxx[0][0] , maxx[i][0]);
	printf("%d" , maxx[0][0]);
	return 0;
}
/*
*/