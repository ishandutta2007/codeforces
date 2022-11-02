#include <bits/stdc++.h>
using namespace std;
int T , n , m , a[1100][1100][3] , b[1100][1100] , val[3] , w[3] , d[3];
string s;
inline int M( int x )
{
	return ((x - 1) % n + n) % n + 1;
}
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &m);
		for(int i = 1 ; i <= n ; i++ )
			for(int j = 1 ; j <= n ; j++ )
				scanf("%d" , &a[i][j][2]) , a[i][j][0] = i , a[i][j][1] = j;
		val[0] = 0 , val[1] = 1 , val[2] = 2; d[0] = d[1] = d[2] = 0;
		cin >> s;
		for(int i = 0 ; i < m ; i++ )
		{
			if(s[i] == 'U') d[0]--;
			if(s[i] == 'D') d[0]++;
			if(s[i] == 'L') d[1]--;
			if(s[i] == 'R') d[1]++;
			if(s[i] == 'I') swap(val[1] , val[2]) , swap(d[1] , d[2]);
			if(s[i] == 'C') swap(val[0] , val[2]) , swap(d[0] , d[2]);
//			cerr << val[0] << ' ' << val[1] << ' ' << val[2] << endl;
		}
		for(int i = 1 ; i <= n ; i++ )
			for(int j = 1 ; j <= n ; j++ )
				b[M(a[i][j][val[0]] + d[0])][M(a[i][j][val[1]] + d[1])] = M(a[i][j][val[2]] + d[2]);
		for(int i = 1 ; i <= n ; i++ )
		{
			for(int j = 1 ; j <= n ; j++ ) printf("%d " , b[i][j]);
			printf("\n");
		}
	}
	return 0;
}
/*
1
3 16
1 2 3
2 3 1
3 1 2
LDICRUCILDICRUCI
*/