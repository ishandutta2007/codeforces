#include <bits/stdc++.h>
using namespace std;
//Coded in localhost
//IP address: 127.0.0.1

int n,m;
int hv[400005];
vector<int> tms[400005];
int all=0;

bool check(int k){
	vector<int> fa(n+1);
	int tm=k,ans=0;
	for(int i=k;i>=1;i--){
		if(tm>i){
			tm=i;
		}
		for(int j=0;j<tms[i].size();j++){
			int buy=min(hv[tms[i][j]]-fa[tms[i][j]],tm);
			fa[tms[i][j]]+=buy;
			ans+=buy;
			tm-=buy;
		}
	}
	return 2*(all-ans)<=k-ans;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",hv+i);
		all+=hv[i];
	}
	for(int i=0;i<m;i++){
		int d,t;
		scanf("%d%d",&d,&t);
		tms[d].push_back(t);
	}
	int l=0,r=400005;
	while(r-l>1){
		int m=(l+r)>>1;
		if(check(m)){
			r=m;
		}else{
			l=m;
		}
	}
	printf("%d\n",r);
	return 0;
}