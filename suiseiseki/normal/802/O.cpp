#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=500000;
const int Inf=2000000000;
int n,k;
int a[Maxn+5],b[Maxn+5];
priority_queue<pair<int,int> > q;
ll sum;
bool check(int x){
	while(!q.empty()){
		q.pop();
	}
	sum=0;
	for(int i=1;i<=n;i++){
		q.push(make_pair(-a[i],0));
		int tmp=b[i]-x-q.top().first;
		if(tmp<0){
			sum+=tmp;
			q.pop();
			q.push(make_pair(b[i]-x,1));
		}
	}
	int cnt=0;
	while(!q.empty()){
		cnt+=q.top().second;
		q.pop();
	}
	return cnt<k;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	int left=0,right=Inf;
	while(left<right){
		int mid=(left>>1)+(right>>1);
		if((left&1)&&(right&1)){
			mid++;
		}
		if(check(mid)){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	check(left);
	printf("%lld\n",sum+1ll*left*k);
	return 0;
}