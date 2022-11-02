#include<bits/stdc++.h>
using namespace std;
int n;
struct square
{
	int l,r,u,d;
	inline void rd()
	{
		l=d=200,r=u=-200;
		int x,y;
		for(int i=0;i<4;i++)
		scanf("%d%d",&x,&y),
		l=min(l,x),d=min(d,y),
		r=max(r,x),u=max(u,y);
	}
}s1,s2;
int mi,ll,rr;
int main()
{
    s1.rd(),s2.rd();
    if(s1.u<s2.d||s1.d>s2.u)return puts("NO"),0;
    mi=(s2.u+s2.d)/2;
    ll=s2.l,rr=s2.r;
    if(s1.d>mi)
	ll-=mi-s1.d,rr+=mi-s1.d;
	else if(s1.u<mi)
	ll+=mi-s1.u,rr-=mi-s1.u;
	if(rr<s1.l||ll>s1.r)puts("NO");
	else puts("YES");
}