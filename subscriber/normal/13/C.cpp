#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>

using namespace std;

int a[5555],id[5555],u[5555],n,e=0;
pair<int,int>q[5555];
long long f[5555],q1[5555],q2[5555],ans=1e15;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n;
	for (int i=0;i<n;i++)cin >> a[i];
	for (int i=0;i<n;i++)q[i]=make_pair(a[i],i);
	sort(q,q+n);
	for (int i=0;i<n;i++){
		if (i&&q[i].first!=q[i-1].first)e++;
		id[q[i].second]=e;
	}
	e++;
	for (int i=0;i<n;i++)u[id[i]]=a[i];
	memset(f,63,sizeof(f));
	f[0]=u[id[0]]-u[0];
	for (int i=0;i<n;i++){
		for (int j=0;j<e;j++)q1[j]=q2[j]=f[j];
		for (int j=1;j<e;j++)if (id[i]>=j)q1[j]=min(q1[j],q1[j-1]-u[j]+u[j-1]);else q1[j]=min(q1[j],q1[j-1]+u[j]-u[j-1]);
		for (int j=0;j<e;j++)f[j]=q1[j]+abs(u[id[i+1]]-u[j]);
	}
	for (int i=0;i<e;i++)ans=min(ans,q1[i]);
	cout << ans << endl;
	return 0;
}