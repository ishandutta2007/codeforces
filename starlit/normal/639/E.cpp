#include<bits/stdc++.h>
const int N=150005;
using namespace std;
typedef long long ll;
int n;
bool fl;
double l,r=1,mi,ans,mx;
struct dat{
	int p,t;ll pre,nxt;
}a[N];
inline ll mul(dat x,dat y){
	return x.t*1ll*y.p-x.p*1ll*y.t;
}
ll sum,al;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].p);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i].t);
	sort(a+1,a+n+1,[](dat x,dat y){
		return mul(x,y)<0;
	});
	a[0].t=1;
	for(int i=1;i<=n;sum+=a[i++].t){
		if(mul(a[i-1],a[i])==0)
		a[i].pre=a[i-1].pre;
		else a[i].pre=sum;
	}al=sum;
	for(int i=n;i;sum-=a[i--].t)
	if(i<n&&mul(a[i+1],a[i])==0)
	a[i].nxt=a[i+1].nxt;
	else a[i].nxt=sum;
	sort(a+1,a+n+1,[](dat x,dat y){
		return x.p<y.p;
	});
	for(;l+1e-8<r;){
		mi=(l+r)/2,mx=fl=0;
		for(int i=1,j=1;i<=n&&!fl;i=j){
			for(;a[j].p==a[i].p;j++)
			if(a[j].p*(1-mi*a[j].nxt/al)<mx)fl=1;
			for(j=i;a[j].p==a[i].p;j++)
			mx=max(mx,a[j].p*(1-mi*(a[j].pre+a[j].t)/al));
		}
		if(fl)r=mi;else l=ans=mi;
	}printf("%.8lf",ans);
}