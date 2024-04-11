#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r;
ll st[200500][20],st2[200500][20],l2[200500],a[200500],pre[200500],sb1,sb2;

ll chk1(int l,int r){int k=l2[r-l+1];return max(st[l][k],st[r-(1<<k)+1][k]);}
ll chk2(int l,int r){int k=l2[r-l+1];return min(st2[l][k],st2[r-(1<<k)+1][k]);}

int main(){
	scanf("%d%d",&n,&t);l2[0]=-1;
	for(i=1;i<=110050;i++){
		l2[i]=l2[i>>1]+1;
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		a[i]-=k;
		pre[i]=pre[i-1]+a[i];
		st[i][0]=st2[i][0]=pre[i];
	}
	for(j=1;j<=18;j++){
		for(i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
	
	while(t--){
		scanf("%d%d",&l,&r);
		sb1=chk1(l,r);
		if(sb1!=pre[l-1]||pre[r]!=pre[l-1]){
			puts("-1");continue;
		}
		printf("%lld\n",sb1-chk2(l,r));
	}
}