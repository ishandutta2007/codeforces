#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int a[200005];
map<int,int> mp;
int Id;
int getId(int p){
	if(mp.count(p)>0){
		return mp[p];
	}
	mp[p]=++Id;
	return Id;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[getId(x)]++;
	}
	sort(a+1,a+1+Id);
	int ans=0;
	int last,now,pos;
	for(int i=1;i<=n;i++){
		last=1;
		now=0;
		for(int k=i;k<=n;k<<=1){
			pos=lower_bound(a+last,a+1+Id,k)-a;
			if(pos>Id){
				break;
			}
			now+=k;
			last=pos+1;
		}
		ans=mx(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}