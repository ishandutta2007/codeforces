#include <bits/stdc++.h>
using namespace std;
char p[222],str[111][222];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)scanf("%s",str[i]);
	scanf("%s",p);
	int len=strlen(p);
	int cnt=0,ans=0;
	for(int i=0;i<n;i++){
		if(strlen(str[i])>len) cnt++;
		if(strlen(str[i])<len) ans++;
	}
	int t=n-cnt;
	int time_max=t+(t-1)/k*5;
	int time_min=ans/k*5+ans+1;
	printf("%d %d",time_min,time_max);
	return 0; 
}