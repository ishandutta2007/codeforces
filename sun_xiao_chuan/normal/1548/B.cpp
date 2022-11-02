#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,res,l2[200500],m,l,r,t,md;

ll st[200500][21],a[200500],sb;
ll chk(int l,int r){int k=l2[r-l+1];return __gcd(st[l][k],st[r-(1<<k)+1][k]);}

int main(){
	scanf("%d",&t);l2[0]=-1;
	for(i=1;i<=200000;i++){
		l2[i]=l2[i>>1]+1;
	}
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==1){puts("1");continue;}
		for(i=1;i<n;i++){
			a[i]=a[i+1]-a[i];
			if(a[i]<0){a[i]=-a[i];}
			st[i][0]=a[i];
		}
		n--;
		for(j=1;j<=19;j++){
			for(i=1;i+(1<<j)-1<=n;i++){
				st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
		//cout<<chk(1,5)<<endl;
		res=0;
		l=1;r=n;
		while(l<=r){
			md=(l+r)>>1;
			for(i=1;i+md-1<=n;i++){
				sb=chk(i,i+md-1);
				if(sb!=1){
					res=max(res,md);l=md+1;goto aaa;
				}
			}
			r=md-1;
			aaa:;
		}
		printf("%d\n",res+1);
	}
}