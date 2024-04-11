#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t;
ll res,a[1050];

ll get(int l,int r){
	ll cur=0,mn=0,l1,r1,sb;
	int i,j,k;
	for(i=l+1;i<r;i++){
		cur+=a[i];
		mn=min(mn,cur);
	}
	if(mn+a[l]<0){
		return 0;
	}
	l1=max(1ll,cur-mn);
	r1=cur+a[l];
	sb=-a[r];
	//printf("a%d %d %d %d %d\n",l,r,l1,r1,sb);
	if(sb>=r1){
		return r1-l1+1;
	}
	if(sb<l1){
		return 0;
	}
	return sb-l1+1;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!(i&1)){
			a[i]=-a[i];
		}
	}
	for(i=2;i<=n;i+=2){
		for(j=1;j<=i;j+=2){
			res+=get(j,i);
		}
	}
	printf("%lld",res);
}