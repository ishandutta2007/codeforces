#include <queue>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=2000;
const int Maxk=16;
const int Maxm=(1<<16);
int n,k,a[16],lg[Maxm|5],m,sum;
bitset<Maxn+5> dp[Maxm|5];
int d[Maxk+5];
priority_queue<pair<int,int> > q;
void dfs(int sta,int s){
	if(!sta){
		return;
	}
	for(;s*k<=sum&&dp[sta][s*k];s*=k){
		for(int t=sta;t;t-=(t&(-t))){
			d[lg[(t&(-t))]]++;
		}
	}
	for(int t=sta;t;t-=(t&(-t))){
		if(s>=a[lg[(t&(-t))]]&&dp[sta-(t&(-t))][s-a[lg[t&(-t)]]]){
			dfs(sta-(t&(-t)),s-a[lg[(t&(-t))]]);
			return;
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	m=(1<<n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		lg[1<<i]=i;
		sum+=a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<m;i++){
		for(int t=i;t;t-=(t&(-t))){
			int v=(t&(-t)),u=lg[v];
			dp[i]|=(dp[i-v]<<a[u]);
		}
		for(int j=sum/k;j>0;j--){
			if(dp[i][j*k]){
				dp[i][j]=1;
			}
		}
	}
	if(!dp[m-1][1]){
		puts("NO");
	}
	else{
		puts("YES");
		dfs(m-1,1);
		for(int i=0;i<n;i++){
			q.push(make_pair(d[i],a[i]));
		}
		for(;q.size()>1;){
			pair<int,int> u=q.top();
			q.pop();
			pair<int,int> v=q.top();
			q.pop();
			printf("%d %d\n",u.second,v.second);
			u.second+=v.second;
			for(;u.second%k==0;u.second/=k){
				u.first--;
			}
			q.push(u);
		}
	}
	return 0;
}