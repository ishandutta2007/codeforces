#include<bits/stdc++.h>
using namespace std;
double a[10011][3];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=1+n;i++) for(int j = 0;j<3;j++) scanf("%lf",&a[i][j]);
	double x,y;
	scanf("%lf %lf",&y,&x);
	scanf("%lf %lf %lf",&a[0][0],&a[0][1],&a[0][2]);
	double tm = 0;
	for(int i = 1;i<=n;i++)
	{
		double s = 0;
		double k = 0;
		for(int j = 0;j<3;j++) 
		{
			s+= (a[i][j]-a[i+1][j])*(a[i][j]-a[i+1][j]);
			k+=	(a[i+1][j]-a[0][j])*(a[i+1][j]-a[0][j]);
		}
		s = sqrt(s);
		k = sqrt(k);
		s = s/x;
		k = k/y;
		if (k-1e-6<=s+tm)
		{	
			double l[3];
			double r[3];
			for(int j = 0;j<3;j++)
			{
				l[j]=a[i][j];
				r[j]=a[i+1][j];
			}
			for (int j=0; j<100; j++)
			{
				double aa[3];
				for(int c = 0;c<3;c++)aa[c]=(l[c]+r[c])/2;
				double u = 0;
				double v = 0;
				for(int c = 0;c<3;c++) 
				{
					u+= (a[i][c]-aa[c])*(a[i][c]-aa[c]);
					v+=	(a[0][c]-aa[c])*(a[0][c]-aa[c]);
				}
				u = sqrt(u);
				u = u/x;
				v = sqrt(v);
				v = v/y;
				if (v < tm + u)
				{
					for(int c = 0;c<3;c++) r[c] =aa[c];
				} 
				else 
				{
					for(int c = 0;c<3;c++) l[c] =aa[c];
				}
			}
			double u = 0;
			for(int c = 0;c<3;c++) 
			{
				u+= (a[i][c]-l[c])*(a[i][c]-l[c]);
			}
			u = sqrt(u);
			u = tm + u/x;
			printf("YES\n");
			printf("%.9lf\n",u);
			printf("%.9lf %.9lf %.9lf\n",l[0],l[1],l[2]);
			return 0;
		}
		tm += s;
	}
	printf("NO\n");
	return 0;
}