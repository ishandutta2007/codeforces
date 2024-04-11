#include<bits/stdc++.h>
using namespace std;
int a,b;
double F[1005][1005];
inline double f(int n, int m)
{
	if(n==0) return 1.0/(m+1.0);
	if(m==0) return 1.0;
	if(F[n][m]) return F[n][m];
    double A=(m+0.0)/(m+1.0)*(1.0-f(m-1,n));
    double B=1.0;
    double C=1.0/(m+1.0)+A;
    double D=1.0-f(m,n-1.0);
	double P=(D-B)/(A-B-C+D);
	return F[n][m]=P*A+(1.0-P)*B;
}

int main()
{
    cin>>a>>b;
    printf("%.12lf %.12lf",f(a,b),1-f(a,b));
}