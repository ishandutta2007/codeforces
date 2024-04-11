#include <cstdio>
#include <map>
using namespace std;
map<int,int> mp;
int a[105];
int ab(int a){
	return a<0?-a:a;
}
bool check(int n,int x,int d){
	for(int i=1;i<=n;i++){
		if(ab(a[i]-x)<d){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]=1;
	}
	int ans=0;
	int x,y;
	for(int i=1;i<=n;i++){
		x=a[i]-d;
		y=a[i]+d;
		if(check(n,x,d)&&!mp[x]){
			ans++;
			mp[x]=1;
		}
		if(check(n,y,d)&&!mp[y]){
			ans++;
			mp[y]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}