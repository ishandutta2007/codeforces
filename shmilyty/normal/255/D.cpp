#include<bits/stdc++.h>
using namespace std;
int n,x,y,c;
int gs(int n)
{
	return (n*n+n)/2;
}
int main()
{
	cin>>n>>x>>y>>c;
	int d,w,s,b;
	int db,ws,wb,ds;
	for(int i=0;;i++)
	{
		db=0,wb=0,ds=0,ws=0,d=0,w=0,s=0,b=0;
		if(i>=x)
			b=(i-x+1)*(i-x+1);
		if(i>=(n-x+1))
			s=(i-n+x)*(i-n+x);
		if(i>=y)
			w=(i-y+1)*(i-y+1);
		if(i>=(n-y+1))
			d=(i-n+y)*(i-n+y);
		if(i>=(1+x+n-y))
			db=gs(i-x-n+y);
		if(i>=(x+y))
			wb=gs(i-x-y+1);
		if(i>=(2+n+n-x-y))
			ds=gs(i-1-n-n+x+y);
		if(i>=(1+y+n-x))
			ws=gs(i-y-n+x);
		if((2*i*i+2*i+1-d-w-s-b+db+wb+ds+ws)>=c)
		{
			cout<<i<<endl;
			return 0; 
		}
	}
	return 0;
}