#include<bits/stdc++.h>
using namespace std;
int need[105][3];
vector<double> ss[105][3];
#define eps 1e-6
struct point{
	double x;
	double y;
}; 
struct seg{
	double a;
	double b;
	double c;
};
point tt[150][3];
seg make_line(point a,point b)
{
	return (seg){a.y-b.y,b.x-a.x,a.x*b.y-a.y*b.x};
}
point make_point(seg a,seg b)
{
	return (point){(-a.b*b.c+a.c*b.b)/(-a.a*b.b+a.b*b.a),(a.a*b.c-a.c*b.a)/(-a.a*b.b+a.b*b.a)};
}
double directed_area(point a,point b,point c)
{
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}
double area(point a,point b,point c)
{
	return abs(a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x);
}
int inside(point x,point a,point b,point c)
{
	if(area(x,a,b) + area(x,b,c) + area(x,c,a) - area(a,b,c) <= eps) return 1;
	return 0;
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		double t[6];
		for(int j = 0;j<6;j++) 
		{
			int z;
			scanf("%d",&z);
			t[j] = (double)z;
		}
		tt[i][0] = (point){t[0],t[1]};
		tt[i][1] = (point){t[2],t[3]};
		tt[i][2] = (point){t[4],t[5]};
	}
	for(int i = 0;i<n;i++) for(int j = 0;j<3;j++) for(int k = 0;k<n;k++) for(int t = 0;t<3;t++)
	{
		if(k==i) continue;
		seg a = make_line(tt[i][j],tt[i][(j+1)%3]);
		seg b = make_line(tt[k][t],tt[k][(t+1)%3]);
		if(abs(a.a*b.b-a.b*b.a) <= eps) continue;
		//if(directed_area(tt[i][j],tt[k][t],tt[k][(t+1)%3])*directed_area(tt[i][(j+1)%3],tt[k][t],tt[k][(t+1)%3])>-eps) continue;
		point x = make_point(a,b);
		//if(area(x,tt[i][j],tt[i][(j+1)%3])>eps) printf("FFFFF\n");
		//if(area(x,tt[k][t],tt[k][(t+1)%3])>eps) printf("FFFFF\n");		
		if(dis(x,tt[i][j])+dis(x,tt[i][(j+1)%3])-dis(tt[i][(j+1)%3],tt[i][j])>=eps) continue;
		//if(dis(x,tt[k][t])+dis(x,tt[k][(t+1)%3])-dis(tt[k][(t+1)%3],tt[k][t])>=eps) continue;
		ss[i][j].push_back(dis(x,tt[i][j])/dis(tt[i][(j+1)%3],tt[i][j]));	
	}
	for(int i = 0;i<n;i++) for(int j = 0;j<3;j++) 
	{
		ss[i][j].push_back(0);
		ss[i][j].push_back(1);
		sort(ss[i][j].begin(),ss[i][j].end());
	}
	double ans = 0;
	for(int i = 0;i<n;i++) for(int j = 0;j<3;j++)
	{
		double temp = 0;
		for(int t = 0;t+1<ss[i][j].size();t++) 
		{
			if(ss[i][j][t+1]-ss[i][j][t]<eps) continue;
			double z = (ss[i][j][t+1] + ss[i][j][t])/2;
			if(z>1) continue;
			point x = (point){tt[i][j].x + z*(tt[i][(j+1)%3].x-tt[i][j].x),tt[i][j].y + z*(tt[i][(j+1)%3].y-tt[i][j].y)};
			int flag = 0;
			for(int k = 0;k<n;k++) if (k!=i) if(inside(x,tt[k][0],tt[k][1],tt[k][2])) flag = 1;
			if(!flag)temp += ss[i][j][t+1] -ss[i][j][t];
			//printf("%d %d %d %d %.9lf\n",flag,i,j,t,ss[i][j][t]);
		}
		ans += dis(tt[i][(j+1)%3],tt[i][j])*temp;
	}
	printf("%.9lf",ans);
	return 0;
}