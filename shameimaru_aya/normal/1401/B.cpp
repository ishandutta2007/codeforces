#include<bits/stdc++.h>
using namespace std;
int T , a1 , a2 , b1 , b2 , c1 , c2 , qwq , ans;
int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d%d" , &a1 , &b1 , &c1);
		scanf("%d%d%d" , &a2 , &b2 , &c2);
		qwq = min(a1 , c2); a1 -= qwq; c2 -= qwq;
		qwq = min(c1 , b2); c1 -= qwq; b2 -= qwq; ans = 2 * qwq;
		qwq = min(c2 , a1 + c1); c2 -= qwq;
		ans -= 2 * min(c2 , b1);
		printf("%d\n" , ans);
	}
    return 0;
}