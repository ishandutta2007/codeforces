#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N=210;
int n;
db ans=n,now;
db p[N],f[N],d[N];
void gnew(int id)
{
	d[id]=1.0+(1-f[id])*p[id]/f[id];
}
int main()
{
	ios::sync_with_stdio(false);
	int i,x,T,id;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		f[i]=p[i]=(db)x/100.0;
		gnew(i);
	}
	now=1;
	for(i=1;i<=n;i++) now*=f[i];
	T=3e5;
	ans=n;
	while(T>0)
	{
		T--;
		ans+=1.0-now;
		id=1;
		for(i=2;i<=n;i++) if(d[i]>d[id]) id=i;
		now*=d[id];f[id]*=d[id];
		gnew(id);
	}
	printf("%.8lf\n",ans);
	return 0;
}