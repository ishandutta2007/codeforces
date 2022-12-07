#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<memory.h>
#include<map>
#include<queue>
#include<list>

using namespace std;

int n,m,cc,dd,a[22],b[22],c[22],d[22],f[3333],ans=0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> cc >> dd;
	for (int i=0;i<m;i++)cin >> a[i] >> b[i] >> c[i] >> d[i];
	memset(f,128,sizeof(f));
	f[0]=0;
	for (int i=0;i<m;i++)for (int k=0;k<a[i]/b[i];k++)
	for (int j=n;j>=0;j--)if (j+c[i]<=n)
	f[j+c[i]]=max(f[j+c[i]],f[j]+d[i]);
	for (int i=0;i<=n;i++)ans=max(ans,f[i]+(n-i)/cc*dd);
	cout << ans << endl;
	return 0;
}