#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 100000
struct Node{
	int a,id;
}a[Maxn+5];
int n,k;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
vector<int> maxn,now;
int ans[Maxn+5],len;
bool vis[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		a[i].id=i;
	}
	srand(time(NULL));
	int num;
	while(1){
		random_shuffle(a+1,a+1+n);
		now.clear();
		now.push_back(a[1].id);
		for(int i=2;i<=n;i++){
			if(gcd(a[i].a,a[1].a)==1){
				now.push_back(a[i].id);
			}
		}
		len=0;
		ans[++len]=a[1].id;
		num=a[1].a;
		for(int i=2;i<=n;i++){
			if(gcd(a[i].a,num)!=1){
				ans[++len]=a[i].id;
				num=gcd(a[i].a,num);
			}
		}
		if(len>=k){
			for(int i=1;i<=k;i++){
				printf("%d ",ans[i]);
			}
			puts("");
			return 0;
		}
		memset(vis,0,sizeof vis);
		len=0;
		for(int i=0;i<(int)now.size();i++){
			ans[++len]=now[i];
			vis[now[i]]=1;
		}
		if(!maxn.empty()&&gcd(a[maxn[0]].a,a[now[0]].a)==1){
			for(int i=0;i<(int)maxn.size();i++){
				if(!vis[maxn[i]]){
					vis[maxn[i]]=1;
					ans[++len]=maxn[i];
				}
			}
		}
		if(len>=k){
			for(int i=1;i<=k;i++){
				printf("%d ",ans[i]);
			}
			puts("");
			return 0;
		}
		if((int)now.size()>(int)maxn.size()){
			maxn=now;
		}
	}
	return 0;
}