#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,a[200500],st[400500][22],l2[400500],m,t,l,r,md,sb[200500],res;

int chk(int l,int r){int k=l2[r-l+1];return __gcd(st[l][k],st[r-(1<<k)+1][k]);}

bool get(int x){
	int i;
	for(i=1;i<=n;i++){
		sb[i]=chk(i,i+x);
		if(i>1&&sb[i]!=sb[i-1]){return 0;}
	}
	return 1;
}

int main(){
	l2[0]=-1;
	for(i=1;i<=400000;i++){
		l2[i]=l2[i>>1]+1;
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			st[i][0]=st[i+n][0]=a[i];
		}
		for(j=1;j<=20;j++){
			for(i=1;i+(1<<j)-1<=n+n;i++){
				st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			}
		}
		l=0;r=n-1;res=1e9;
		while(l<=r){
			md=(l+r)/2;
			if(get(md)){res=min(res,md);r=md-1;}
			else{l=md+1;}
		}
		printf("%d\n",res);
	}
}