#include<bits/stdc++.h>
using namespace std;
#define int long long
int qry(vector<int>&p){
	cout<<"? "<<p.size()<<" ";
	for(int j=0;j<p.size();++j)
		cout<<p[j]<<" ";
	cout<<endl;
	int v;cin>>v;
	return v;
}
#define mn (1<<13|5)
int n,a[mn],ans[mn],v[15];
int tot,cnt[mn],val[mn],id[mn];;
void init(){
	for(int i=1;i<(1<<13);++i){
		cnt[i]=cnt[i>>1]+(i&1);
		if(cnt[i]==6){
			id[i]=++tot;
			val[tot]=i;
		}
	}
}
signed main(){
	init();
	cin>>n;
	int all=0;
	for(int i=0;i<13;++i){
		vector<int>p(0);
		for(int j=1;j<(1<<13);++j)
			if(id[j]&&id[j]<=n&&((j>>i)&1))p.push_back(id[j]);
		if(p.empty())continue;
		v[i]=qry(p);
		all|=v[i];
	}
	for(int i=1;i<=n;++i){
		ans[i]=all;int a=(1ull<<63)-1,b=0;
		for(int j=0;j<13;++j){
			if((val[i]>>j)&1)a&=v[j];
			else {
				b|=v[j];
			}
		}
		ans[i]^=a^(a&b);
	}
	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}