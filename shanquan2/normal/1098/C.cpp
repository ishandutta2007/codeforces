#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,k,a[100005],p[100005];
long long s;
int main(){
	cin>>n>>s;
	if(s>(n*1ll*(n+1))/2||s<2*n-1){
		printf("No\n");
		return 0;
	}
	if(s==(n*1ll*(n+1))/2){
		printf("Yes\n");
		for(int i=1;i<n;i++)printf("%d ",i);printf("\n");
		return 0;
	}
	for(k=1;k<=n;k++){
		long long t=1,c=1,cnt=1,dep=1;
		while(cnt<n){
			c*=k;dep++;
			t+=dep*min(c,n-cnt);
			cnt+=c;
		}
		if(t<=s)break;
	}
	printf("Yes\n");
	long long t=1,c=1,cnt=1,dep=1;
	a[1]=1;
	while(cnt<n){
		c*=k;dep++;
		a[dep]=min(c,n-cnt);
		t+=dep*a[dep];
		cnt+=c;
	}
	int up=dep,down=dep+1;
	s-=t;
	while(s){
		if(a[up]<=1)up--;
		a[up]--;
		int tar=down++;
		if(tar-up>s)tar=up+s;
		a[tar]++;
		s-=tar-up;
	}
//	for(int i=1;i<down;i++)printf("%d ",a[i]);printf("\n");
	int lst=1;
	for(int i=2;i<down;i++){
		int now=lst+a[i],nowp=lst-a[i-1]+1,nowk=0;
		for(int j=lst+1;j<=now;j++){
			if(nowk==k)nowp++,nowk=0;
			nowk++;p[j]=nowp;
		}
		lst=now;
	}
	for(int i=2;i<=n;i++)printf("%d ",p[i]);printf("\n");
	return 0;
}