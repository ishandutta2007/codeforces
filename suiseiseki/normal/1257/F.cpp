#include <map>
#include <vector>
#include <cstdio>
using namespace std;
#define Maxn 100
int n;
int a[Maxn+5];
map<vector<int>,int> mp;
int count(int x){
	int ans=0;
	while(x){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int x=0;x<(1<<15);x++){
		vector<int> now;
		for(int i=1;i<=n;i++){
			now.push_back(count((a[i]^x)&((1<<15)-1)));
		}
		for(int i=1;i<n;i++){
			now[i]-=now[0];
		}
		now[0]=0;
		mp[now]=x;
	}
	for(int x=0;x<(1<<15);x++){
		vector<int> now;
		for(int i=1;i<=n;i++){
			now.push_back(count((a[i]>>15)^x));
		}
		for(int i=1;i<n;i++){
			now[i]-=now[0];
		}
		now[0]=0;
		for(int i=0;i<n;i++){
			now[i]=-now[i];
		}
		if(mp.count(now)>0){
			printf("%d\n",(x<<15)+mp[now]);
			return 0;
		}
	}
	puts("-1");
	return 0;
}