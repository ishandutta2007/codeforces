#include<bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
ll ans;
int n,a[N],b[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d%d",a+i,b+i),ans+=b[i]+1;
	sort(a,a+n),sort(b,b+n);
	for(int i=0;i<n;i++)
	if(a[i]>b[i])ans+=a[i]-b[i];
	printf("%I64d",ans);
}