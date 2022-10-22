#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define pb push_back
using namespace std;
int T;
int n;
int dep[1010];
vector<int>st[1010],vec[1010];
int maxn;
int x,d,tmp;
char s[2130];
void dfs(int x,int fa){
//	printf("x:%d,fa:%d\n",x,fa);fflush(stdout);
	if(dep[fa]+1>tmp) return ;
	dep[x]=dep[fa]+1;
	st[dep[x]].pb(x);
	for(auto i:vec[x]){
		if(i==fa) continue ;
		dfs(i,x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	dep[0]=-1;
	cin>>T;
	while(T--){
		vector<int>empty[3010];
		cin>>n;
		for(int i=0;i<=n;++i) swap(vec[i],empty[i]),swap(st[i],empty[i+n+1]),dep[i]=-1;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
			vec[u].pb(v);vec[v].pb(u);
		}
		cout<<"? "<<n<<" ";
		for(int i=1;i<=n;++i) cout<<i<<(i==n?"\n":" ");
		cout.flush();
		int rt;cin>>rt>>maxn;
		tmp=maxn;
		dfs(rt,0);
		int ans1=-1,ans2=-1;
		maxn=0;
		for(int i=1;i<=n;++i) maxn=max(maxn,dep[i]);
		int l=max(1,(tmp>>1)),r=maxn;
		while(l<=r){
			int mid=l+r>>1;
		if(st[mid].size()==0) {
			printf("? 1 -1238013\n");fflush(stdout);
		}
			cout<<"? "<<st[mid].size()<<" ";
			for(int i=0;i<st[mid].size();++i) cout<<st[mid][i]<<(i==st[mid].size()-1?"\n":" ");
			cout.flush();
			cin>>x>>d;
			if(d==tmp){
				l=mid+1;ans1=x;
			}
			else{
				r=mid-1;
			}
		}
		for(int i=0;i<=n;++i)swap(st[i],empty[i+n+n+2]);
		dfs(ans1,0);
		if(st[tmp].size()==1){
			ans2=st[tmp][0];
			cout<<"! "<<ans1<<" "<<ans2<<"\n";cout.flush();
			scanf("%s",s+1);
			continue ;
		}
		if(st[tmp].size()==0) {
			printf("? 1 1238013\n");fflush(stdout);
		}
		cout<<"? "<<st[tmp].size()<<" ";
		for(int i=0;i<st[tmp].size();++i) cout<<st[tmp][i]<<(i==st[tmp].size()-1?"\n":" ");
		cout.flush();
		cin>>ans2>>d;
		cout<<"! "<<ans1<<" "<<ans2<<"\n";cout.flush();
		scanf("%s",s+1);
	}
}