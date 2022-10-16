#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=500;
int n;
int sz[Maxn+5],p[Maxn+5];
set<int> S;
vector<pair<int,int> > ans;
bool cmp(int p,int q){
	return sz[p]>sz[q];
}
int check(int u,int left,int right){
	set<int>::iterator it=S.begin();
	int v;
	printf("%d\n",right-left+1);
	for(int i=1;i<left;i++){
		it++;
	}
	for(int i=left;i<=right;i++){
		printf("%d ",v=(*it));
		it++;
	}
	printf("\n1\n%d\n%d\n",1,u);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&n);
	sz[1]=n;
	for(int i=2;i<=n;i++){
		printf("%d\n",n-1);
		for(int i=2;i<=n;i++){
			printf("%d ",i);
		}
		printf("\n1\n1\n%d\n",i);
		fflush(stdout);
		scanf("%d",&sz[i]);
	}
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	sort(p+1,p+1+n,cmp);
	for(int i=n;i>0;i--){
		if(!S.empty()){
			int begin=1,left,right;
			while(!S.empty()&&check(p[i],begin,S.size())){
				left=begin,right=S.size();
				while(left<=right){
					int mid=(left+right)>>1;
					if(check(p[i],left,mid)){
						right=mid-1;
					}
					else{
						left=mid+1;
					}
				}
				set<int>::iterator it=S.begin();
				for(int j=1;j<left;j++){
					it++;
				}
				ans.push_back(make_pair(p[i],*it));
				S.erase(*it);
			}
		}
		S.insert(p[i]);
	}
	puts("ANSWER");
	for(int i=0;i<(int)ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	fflush(stdout);
	return 0;
}