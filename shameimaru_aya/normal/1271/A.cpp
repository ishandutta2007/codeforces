#include<bits/stdc++.h>
using namespace std;
int a , b , c , d , e , f , ans;
int main()
{
	scanf("%d%d%d%d%d%d" , &a , &b , &c , &d , &e , &f);
	if(e > f)
	{
		int qwq = min(a , d);
		a -= qwq;
		d -= qwq;
		ans += qwq * e;
		qwq = min(b , min(c , d));
		ans += qwq * f;
	}
	else
	{
		int qwq = min(b , min(c , d));
		b -= qwq; c -= qwq; d -= qwq;
		ans += qwq * f;
		qwq = min(a , d);
		a -= qwq;
		d -= qwq;
		ans += qwq * e;
	}
	printf("%d" , ans);
	return 0;
}