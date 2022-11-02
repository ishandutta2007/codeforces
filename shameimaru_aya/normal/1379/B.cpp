#include<bits/stdc++.h>
using namespace std;
int T , l , r , ans , B , C , QWQ;
long long m , a , b , minn , maxx;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		bool flag = 0;
		scanf("%d%d%lld" , &l , &r , &m);
		minn = m - r + l , maxx = m + r - l;
		//m - r + l <= m + c - b <= m - l + r
		for(int i = l ; i <= r ; i++ )
		{
			a = minn / i , b = maxx / i;
			if(b - a >= 1)
			{
				QWQ = m - b * i;
				if(QWQ > 0) B = r , C = r - QWQ;
				else B = l , C = l - QWQ;
				printf("%d %d %d\n" , i , B , C);
				flag = 1;
			}
			else
			{
				if(minn % i == 0)
				{
					QWQ = m - b * i;
					if(QWQ > 0) B = r , C = r - QWQ;
					else B = l , C = l - QWQ;
					printf("%d %d %d\n" , i , B , C);
					flag = 1;
				}
			}
			if(flag) break;
		}
	}
    return 0;
}