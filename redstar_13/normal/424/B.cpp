#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair <double,int> pii;
pii q[1010];
int y[1010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	int a,b;
	int T=0;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>q[i].y;
		T+=q[i].y;
		q[i].x=sqrt(a*a*1.0+b*b*1.0);
	}
	if(T+m<1000000) {cout<<-1<<endl;return 0;}
	sort(q+1,q+n+1);
	m=1000000-m;
	int s=0;int t;
	for(int i=0;i<=n;i++) {
		if(m<=s) {t=i;break;}
		s+=q[i+1].y;
	}
	printf("%.10lf",q[t].x);
	return 0;
}