#include <bits/stdc++.h>
using namespace std;
typedef long double db;
typedef long long ll;
#define double db
const double p=acos(-1),eps=1e-10,pps=1e-6;
const int N=4e5+2;
typedef pair<double,int> pa;
pa a[N];
int n,i,m,q;
void mdf(double l,double r)
{
	a[++q]=pa(l,-1);a[++q]=pa(r,1);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	cin>>n>>m;
	vector<pair<int,int>> x(n);
	for (auto &[x,y]:x) cin>>x>>y;
	double L=0,R=2e5,M;
	while (R-L>max((db)1,L)*eps)
	{
		M=(L+R)*0.5;
		double r=M;q=0;
		int now=0,ans=0;
		for (auto [x,y]:x)
		{
			if ((ll)x*x+(ll)y*y>4*r*r) continue;
			if (x==0&&y==0) {++ans;++now;continue;}
			double z=atan2(y,x),t,L,R;
			if (z<0) z+=p*2;
			t=acos((sqrt((ll)x*x+(ll)y*y)*0.5)/r);
			L=z-t;R=z+t;//if (fabs(2-r)<=eps*5) cout<<L<<' '<<R<<endl;
			if (L>=0&&R<2*p-eps*1000) mdf(L,R); else if (R>=2*p) mdf(0,R-p*2),mdf(L,p*2); else mdf(0,R),mdf(L+p*2,p*2);
		}
		sort(a+1,a+q+1);
		for (i=1;i<=q;i++) ans=max(ans,now-=a[i].second);
		if (ans>=m) R=M; else L=M;
	}
	cout<<(double)(L+R)*0.5;
}