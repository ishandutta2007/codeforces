#include<bits/stdc++.h>
using namespace std;
int T , num[200000] , zl[200000] , tot , l , a , m , ans , anss[200000] , pl;
char s[200000];
int numm( char c )
{
	if(c == 'o') return 1;
	if(c == 'n') return 2;
	if(c == 'e') return 3;
	if(c == 't') return 4;
	if(c == 'w') return 5;
	return 0;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		tot = 0; a = 6; ans = 0; pl = 1; m = 0;
		scanf("%s" , s); l = strlen(s);
		for(int i = 0 ; i < l ; i++ )
		{
			if(numm(s[i]) != a)
			{
				zl[++tot] = a;
				num[tot] = m;
				m = 1; a = numm(s[i]);
			}
			else m++;
		}
		zl[++tot] = a;
		num[tot] = m;
		for(int i = 1 ; i <= tot - 2 ;  )
		{
//			cerr << i << ' ' << pl << endl;
			if(zl[i] == 1 && zl[i + 1] == 2 && zl[i + 2] == 3 && num[i + 1] == 1)
			{
				pl += num[i];
				anss[++ans] = pl;
				pl += num[i + 1] + num[i + 2];
				i += 3;
				continue;
			}
			if(zl[i] == 4 && zl[i + 1] == 5 && zl[i + 2] == 1 && num[i + 1] == 1)
			{
				if(i <= tot - 4 && zl[i + 3] == 2 && zl[i + 4] == 3 && num[i + 3] == 1)
				{
					if(num[i + 2] < 2)
					{
						pl += num[i + 1] + num[i];
						anss[++ans] = pl;
						pl += num[i + 2] + num[i + 3] + num[i + 4];
					}
					else
					{
						pl += num[i];
						anss[++ans] = pl;
						pl += num[i + 1] + num[i + 2];
						anss[++ans] = pl;
						pl += num[i + 3] + num[i + 4];
					}
					i += 5;
				}
				else
				{
					pl += num[i];
					anss[++ans] = pl;
					pl += num[i + 1] + num[i + 2];
					i += 3;
				}
				continue;
			}
			pl += num[i];
			i++;
		}
		printf("%d\n" , ans);
		for(int i = 1 ; i <= ans ; i++ )
		{
			printf("%d " , anss[i]);
		}
		printf("\n");
	}
	return 0;
}