#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
int con=1100000;
int maxy=0,miny=con*3;
int maxx[2200000],minx[2200000];
int main()
{
	int i,n,a=0,b=0,c=con*3,d=con*3,x,y;
	for(i=0;i<con*2;i++){maxx[i]=0;minx[i]=con*3;}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);x+=con;y+=con;
		maxx[y]=max(maxx[y],x);minx[y]=min(minx[y],x);
		miny=min(miny,y);maxy=max(maxy,y);
	}
	for(i=miny;i<=maxy;i++){
		if(maxx[i]<=0 || minx[i]>=con*3) continue;
		a=max(a,1+maxx[i]-(i-miny));b=max(b,1+maxx[i]-(maxy-i));
		c=min(c,i-miny-1+minx[i]);d=min(d,maxy-i-1+minx[i]);
	}
//	cout<<maxy<<' '<<miny<<' '<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	cout<<2*(maxy-miny)+(a-c)+(b-d)<<endl;
	return 0;
}