#include<bits/stdc++.h>
using namespace std;
int T , x , w[110000] , p[110000] , flag;
string s;
inline bool upd0( int k )
{
	if(w[k] == 1 && ~p[k])
	{
		if(!w[p[k]]) 
		{
			printf("-1\n");
			return 0;
		}
		w[p[k]] = 1; p[p[k]] = -1;
		w[k] = 0; p[k] = -1;
		return 1;
	}
	if(w[k] == 1 && p[k] == -1)
	{
		printf("-1\n");
		return 0;
	}
	w[k] = 0;
	return 1;
}
inline bool upd1( int k , int qwq )
{
	if(k <= 0 || k > s.size()) return 0;
	if(w[k] == 0) return 0;
	if(w[k] == 1) return 1;
	w[k] = 1;
	p[k] = qwq;
	return 1;
}
int main()
{
	cin >> T;
	while(T--)
	{
		flag = 0;
		cin >> s >> x;
		for(int i = 1 ; i <= s.size() ; i++ )
		{
			w[i] = p[i] = -1;
		}
		for(int i = 1 ; i <= s.size() ; i++ )
		{
			if(s[i - 1] == '0')
			{
				if(i - x > 0)
				{
					if(!upd0(i - x))
					{
						flag = 1;
						break;
					}
				}
				if(i + x <= s.size())
				{
					if(!upd0(i + x))
					{
						flag = 1;
						break;
					}
				}
			}
			else
			{
				if(!(upd1(i - x , -1) | upd1(i + x , i - x)))
				{
					printf("-1\n");
					flag = 1;
					break;
				}
			}
		}
		if(flag) continue;
		for(int i = 1 ; i <= s.size() ; i++ )
		{
			if(w[i] == -1) w[i] = 1;
			printf("%d" , w[i]);
		}
		printf("\n");
	}
    return 0;
}
/*
1
11100
1
*/