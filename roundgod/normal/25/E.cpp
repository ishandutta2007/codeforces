#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef unsigned long long ull;
const ull B=1000000007;
string a,b,c;
bool contain(string a,string b)
{
	int al=a.length(),bl=b.length();
	if(al>bl) return false;
	ull t=1;
	for(int i=0;i<al;i++)
		t*=B;
	ull ah=0,bh=0;
	for(int i=0;i<al;i++) ah=ah*B+a[i];
	for(int i=0;i<al;i++) bh=bh*B+b[i];
	for(int i=0;i+al<=bl;i++)
	{
		if(ah==bh) return true;
		if(i+al<bl) bh=bh*B+b[i+al]-b[i]*t;
	}
	return false;
}
int maxsame(string a,string b)
{
	int al=a.length(),bl=b.length();
	ull t1=0,t2=0,t=1;
	int cnt,ans=0;
	for(cnt=1;cnt<=min(al,bl);cnt++)
	{
		t1=t1+a[al-cnt]*t;
		t2=t2*B+b[cnt-1];
		t=t*B;
		if(t1==t2) ans=cnt;
	}
	return ans;
}
int main()
{
	cin>>a>>b>>c;
	int ans=0;
	if(contain(a,b)||contain(a,c)) a="";
	if(contain(b,c)||contain(b,a)) b="";
	if(contain(c,a)||contain(c,b)) c="";
	ans=max(ans,maxsame(a,b)+maxsame(b,c));
	ans=max(ans,maxsame(a,c)+maxsame(c,b));
	ans=max(ans,maxsame(b,a)+maxsame(a,c));
	ans=max(ans,maxsame(b,c)+maxsame(c,a));
	ans=max(ans,maxsame(c,a)+maxsame(a,b));
	ans=max(ans,maxsame(c,b)+maxsame(b,a));
	printf("%d\n",a.length()+b.length()+c.length()-ans);
	return 0;
}