#include <bits/stdc++.h>
using namespace std;
int n , p[110] , a[110] , id[110] , qwq;
int query( int k , int d )
{
	if(d >= n) return qwq = 0;
	printf("? ");
	for(int i = 1 ; i <= n ; i++ )
	{
		if(i == k) printf("%d " , d + 1);
		else printf("1 ");
	}
	printf("\n");
	fflush(stdout);
	
	scanf("%d" , &qwq);
	return qwq;
}
int main()
{
	scanf("%d" , &n); int maxx = n;
	for(int r = n ; r >= 1 ; r-- )
	{
		if(p[r]) continue;
		for(int i = 1 ; i <= n ; i++ )
		{
			query(r , i);
			if(qwq && !p[qwq] && qwq != r) id[i] = qwq;
			else
			{
				p[r] = maxx - i + 1; maxx--;
//				cerr << r << ' ' << maxx << ' ' << i << endl;
				for(int j = 1 ; j < i ; j++ )
				{
//					cerr << r << ' ' << p[r] << ' ' << id[j] << ' ' << p[r] + j << endl;
					p[id[j]] = p[r] + j; maxx--;
				} 
				break;
			}
		}
//		if(p[r] == maxx) maxx--;
	}
	printf("! ");
	for(int i = 1 ; i <= n ; i++ ) printf("%d " , p[i]); printf("\n");
	fflush(stdout);
	return 0;
}
/*
4 3
.X.
.X.
X..
X..
1
1 3

*/