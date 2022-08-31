#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N],n;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int cur=1,ans=0;
	rep(i,n){
		if(cur<i&&a[cur]<a[i])++ans,++cur;
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}