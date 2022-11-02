#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;
const int N = 4e5+10;

int n,c[N],ans,pw[30],w[20000010];

inline void Sort(int x){
	x = min(x,23);
	for(int i=1;i <= pw[x+1];i++) w[i] = 0;
	for(int i=1;i <= n;i++)
		c[i] &= (pw[x+1]-1) , w[c[i]]++;
	int top = 0;
	for(int i=pw[x+1];i >= 0;i--)
		while(w[i]) c[++top] = i , w[i]--;
}

inline int find(int x,int v){
	int l = x,r = n,ans;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(c[mid] <= v)
			ans = mid , r = mid-1;
		else
			l = mid+1;
	}
	if(c[n] > v) return 0;
	return n-ans+1;
}

inline int findd(int x,int v){
	int l = x,r = n,ans;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(c[mid] >= v)
			ans = mid , l = mid+1;
		else
			r = mid-1;
	}
	if(c[x] < v) return 0;
	return ans-x+1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++)
		scanf("%d",&c[i]);
	pw[0] = 1;
	for(int i=1;i <= 25;i++) pw[i] = pw[i-1] << 1;
	for(int k=24;k >= 0;k--){
		Sort(k);
		long long cnt = 0;
		for(int i=1;i < n;i++){
			if(c[i]&pw[k]){
				cnt += find(i+1,pw[k]-(c[i]^pw[k])-1);
				cnt += findd(i+1,pw[k+1]-(c[i]^pw[k]));
			}
			else cnt += findd(i+1,pw[k]-c[i]);
		}
		ans += ((cnt&1)*pw[k]);
	}
	printf("%d\n",ans);
	return 0;
}