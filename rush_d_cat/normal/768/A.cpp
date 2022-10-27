#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,a[N];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)if(a[i]!=a[1]&&a[i]!=a[n])ans++;
	cout<<ans<<endl;
}