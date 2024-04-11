#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
#define NN 100010
int a[NN];
int ansb[NN],anse[NN];
int sum[NN],cnt[NN];
int L[NN],R[NN];
int n;
int r;
int flag;
void calc(){
	r=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n+1-i]){
			r=i;
			break;
		}
	}
	int s=n+1-r;
	int mid=(n+1)/2;
	int p;
	for(int i=mid;i>=r;i--){
		if(a[i]!=a[n+1-i]){
			p=i;
			break;
		}
	}
	int q=n+1-p;
	for(int i=r;i<=p;i++) L[a[i]]++;
	for(int i=q;i<=s;i++) R[a[i]]++;
	flag=0;
	for(int i=r;i<=p;i++){
		if(L[a[i]]!=R[a[i]]){
			flag=1;
		}
	}
	int st,ed=0;
	if(!flag){
		st=p;
		ed=n+1-p;
	}
	else{
		for(int i=r;i<=s;i++) sum[a[i]]++;
		for(int i=s;i>=r;i--){
			anse[a[i]]++;
			if(anse[a[i]]>sum[a[i]]/2){
				st=i;
				break;
			}
		}
		for(int i=r;i<=s;i++){
			ansb[a[i]]++;
			if(ansb[a[i]]>sum[a[i]]/2){
				ed=i;
				break;
			}
		}
	}
	printf("%I64d\n",(INT)r*(n-st+1)+(INT)ed*(n-s+1)-(INT)r*(n+1-s));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n+1-i]){
			flag=1;
			break;
		}
	}
	if(!flag){
		printf("%I64d\n",(INT)n*(n+1)/2);
		return 0;
	}
	flag=0;
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	r=0;
	for(int i=1;i<=n;i++){
		if(r!=0&&cnt[a[i]]%2==1&&a[i]!=r) flag=1;
		if(cnt[a[i]]%2==1){
			r=a[i];
		}
	}
	if(flag){
		printf("%d\n",0);
		return 0;
	}
	calc();
    return 0;
}