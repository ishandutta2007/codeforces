#include<bits/stdc++.h>
using namespace std;

int n,c[205],num=1e9;
vector<int> a,ans;
void dfs(int n,vector<int> a,int d,int t){
//	printf("%d\n",n);
//	for(int i=0;i<a.size();i++)printf("%d ",a[i]);printf("\n");
	if(n==0){
		if(d<num){
			ans.clear();num=d;
			for(int i=0;i<d;i++)ans.push_back(c[i]);
		}
		return;
	}
	int m=a.size();
	bool f=1;
	for(int i=0;i<m;i++)if(a[i]%2!=0){
		f=0;break;
	}
	if(f){
		for(int i=0;i<m;i++)a[i]/=2;
		return dfs(n/2,a,d,t+1);
	}
	if(m==2&&a[0]==0&&a[1]==1||m==1&&a[0]==1){
		c[d]=1<<t;
		return dfs(0,a,d+1,t+1);
	}
	if(m==2&&a[0]==-1&&a[1]==0||m==1&&a[0]==-1){
		c[d]=-(1<<t);
		return dfs(0,a,d+1,t+1);
	}
	//1
	vector<int> b;
	b.clear();
	int lst=-1e9;
	for(int i=0;i<m;i++){
		int u=a[i];
		if(u%2==0)u/=2;else u=(u-1)/2;
		if(u!=lst){
			b.push_back(u);
			lst=u;
		}
	}
	c[d]=1<<t;
	dfs((n+1)/2,b,d+1,t+1);
	//-1
	b.clear();
	lst=-1e9;
	for(int i=0;i<m;i++){
		int u=a[i];
		if(u%2==0)u/=2;else u=(u+1)/2;
		if(u!=lst){
			b.push_back(u);
			lst=u;
		}
	}
	c[d]=-(1<<t);
	dfs((n+1)/2,b,d+1,t+1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	dfs(100000,a,0,0);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);printf("\n");
	return 0;
}