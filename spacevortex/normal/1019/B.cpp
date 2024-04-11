#include<bits/stdc++.h>
using namespace std;
int qry(int x)
{
	int ret;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
void answer(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
const int N=2e5+50;
int n;
int add(int a,int b){a+=b;if(a>n) a-=n;return a;}
int sub(int a,int b){a-=b;if(a<1) a+=n;return a;}
int get(int x)
{
	return qry(x)-qry(add(x,n>>1));
}
int ch(int x)
{
	if(x<0) return -1;
	else if(x==0) return 0;
	else return 1;
}
int main()
{
	int sl,sr,mid,vl;
	scanf("%d",&n);
	if(n%4==2)
	{
		answer(-1);return 0;
	}
	vl=get(1);
	if(vl==0)
	{
		answer(1);return 0;
	}
	sl=2;sr=n;
	while(sl<sr)
	{
		mid=(sl+sr)>>1;
		if(ch(get(mid))!=ch(vl)) sr=mid;
		else sl=mid+1;
	}
	answer(sl>(n>>1)?sl-(n>>1):sl);
	return 0;
}