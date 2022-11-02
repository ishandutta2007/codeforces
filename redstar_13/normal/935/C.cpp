#include<bits\stdc++.h>
using namespace std;
typedef long long INT;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	double r,x1,x2,y1,y2,x,y;
	cin>>r>>x1>>y1>>x2>>y2;
	double m=hypot((x1-x2),(y1-y2));
	if(m>=r+1e-10) printf("%.12lf %.12lf %.12lf\n",x1,y1,r);
	else if(m<1e-8)printf("%.12lf %.12lf %.12lf\n",x1+r/2,y1,r/2);
	else{
		double R=(m+r)/2;
		double len=r/m;
		x=(x2+x1-len*(x2-x1))/2;
		y=(y2+y1-len*(y2-y1))/2;
		printf("%.12lf %.12lf %.12lf\n",x,y,R);
	}
}