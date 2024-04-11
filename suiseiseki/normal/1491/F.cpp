#include <vector>
#include <cstdio>
using namespace std;
const int Maxn=2000;
int ask(vector<int> l,vector<int> r){
	printf("? %d %d\n",(int)l.size(),(int)r.size());
	for(int i=0;i<(int)l.size();i++){
		printf("%d%c",l[i],(i==(int)l.size()-1?'\n':' '));
	}
	for(int i=0;i<(int)r.size();i++){
		printf("%d%c",r[i],(i==(int)r.size()-1?'\n':' '));
	}
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
bool vis[Maxn+5];
int val[Maxn+5];
vector<int> lis;
vector<int> ans;
bool work(vector<int> lis,bool flag=1){
	if((!flag)&&ask(ans,lis)==0){
		return 0;
	}
	if((int)lis.size()==1){
		ans.push_back(lis[0]);
		return 1;
	}
	int mid=(((int)lis.size())>>1);
	vector<int> tmp;
	for(int i=0;i<mid;i++){
		tmp.push_back(lis[i]);
	}
	if(work(tmp,0)){
		return 1;
	}
	tmp.clear();
	for(int i=mid;i<(int)lis.size();i++){
		tmp.push_back(lis[i]);
	}
	if(work(tmp,1)){
		return 1;
	}
	return 0;
}
void solve(){
	lis.clear();
	ans.clear();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=2;i<=n;i++){
		lis.push_back(i-1);
		vector<int> tmp;
		tmp.push_back(i);
		val[i]=ask(tmp,lis);
		if(val[i]!=0){
			ans.push_back(i);
			work(lis);
			for(int j=i+1;j<=n;j++){
				tmp.clear();
				tmp.push_back(j);
				lis.clear();
				lis.push_back(i);
				if(ask(lis,tmp)!=0){
					ans.push_back(j);
				}
			}
			break;
		}
	}
	for(int i=0;i<(int)ans.size();i++){
		vis[ans[i]]=1;
	}
	printf("! ");
	printf("%d ",n-(int)ans.size());
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			printf("%d ",i);
		}
	}
	puts("");
	fflush(stdout);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}