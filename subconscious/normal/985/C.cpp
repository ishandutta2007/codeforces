#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=1e5+5,inf=0x3f3f3f3f;
int a[N],n,k,l,m;
int main(){
	scanf("%d%d%d",&n,&k,&l);m=n*k;
	rep(i,m)scanf("%d",a+i);
	sort(a+1,a+m+1);
	int pos=1;
	while(pos<m&&a[pos+1]-a[1]<=l)++pos;
	ll ans=0;
	rep(i,n){
		while(m-i*k+1<pos)--pos;
		//printf("%d\n",a[pos]);
		ans+=a[pos];--pos;
		if(pos==0&&i!=n){pos=-1;break;}
	}
	if(pos==-1)ans=0;
	printf("%lld\n",ans);
	//system("pause");
}