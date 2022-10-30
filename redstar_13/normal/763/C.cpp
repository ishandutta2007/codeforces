#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
#define NN 200010
int a[NN];
int cnt[NN];
int vst[NN];
int f;
map<int,int> mp;
int power(int a, int b, int m, int ans=1) {
    for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int m,n;
	scanf("%d%d",&m,&n);
	int flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(n>=m) cnt[a[i]]++;
	}
	if(n==m||n==1){
		printf("%d %d\n",a[1],1);
		return 0;
	}
  	if(m==2){
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			if(a[i]) x++;
			else y++;
		}
		int st=0;
		if(x>=y) st=1;
		if(abs(x-y)>1) puts("-1");
		else printf("%d %d\n",st,1);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			puts("-1");
			return 0;
		}
	}
	flag=0;
	int Flag=0;
	if(2*n>=m){
		Flag=1;
		for(int i=1;i<=n;i++) vst[a[i]]=1;
		n=0;
		for(int i=0;i<m;i++){
			if(!vst[i]) a[++n]=i;
		}
	}
	if(n==1){
		printf("%d %d\n",(a[1]+1)%m,1);
		return 0;
	}
	int dk=a[2]-a[1],k=0;
	for(int i=1;i<=n;i++) mp[a[i]]=1;
	for(int i=1;i<=n;i++){
		int xx=(a[i]+dk)%m;
		if(!mp.count(xx)) k++;
	}
	int d=(INT)dk*power(k,m-2,m)%m;
	flag=0;
	int st=0;
	for(int i=1;i<=n;i++){
		int xx=(a[i]+d)%m;
		if(!mp.count(xx)){
			if(flag){
				f=1;
				break;
			}
			flag=1;
			st=(xx-(INT)n*d)%m;
			if(st<0) st+=m;
		}
	}
	if(!flag) f=1;
	flag=0;
	for(int j=0;j<n;j++){
		int xx=(st+(INT)d*j)%m;
		if(!mp.count(xx)){
			flag=1;
			break;	
		}
	}
	if(!flag){
		if(Flag) st=(st+(INT)n*d)%m;
		if(!f){
			printf("%d %d\n",st,d);
			return 0;
		}
	}
	
	puts("-1");
    return 0;
}