#include<bits/stdc++.h>
using namespace std;
using nagai=long long;
#define sz(x) (int)(x.size())

const int S=500500;
vector<int>occ[S];
int cnt[S];
const int oo=0x3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,k,n,s;
	cin>>m>>k>>n>>s;
	vector<int>a(m);
	for(auto&x:a)cin>>x;
	vector<int>b(s);
	for(auto&x:b)
		cin>>x,++cnt[x];
	for(int i=0;i<m;++i)
		occ[a[i]].push_back(i);
	int mx=0;
	for(int i=0;i<S;++i){
		if(cnt[i]==0)continue;
		if(cnt[i]>sz(occ[i])){mx=oo;continue;};
		mx=max(mx,occ[i][cnt[i]-1]);
	}
	int ans=oo,ansi=-1,ansj=-1;
	for(int i=0;i<m;++i){
		if(mx==oo)break;
//		cerr<<i<<' '<<mx<<'\n';
		int cnt=max(0,(mx-i+1)-k);
		cnt+=i%k;
		if(cnt<ans)
			ans=cnt,ansi=i,ansj=max(mx,i+k-1);
		if(::cnt[a[i]]){
			int x=a[i];
			int mem=upper_bound(occ[x].begin(),occ[x].end(),i)-occ[x].begin();
			if(mem+::cnt[x]>sz(occ[x]))
				break;
			mx=max(mx,occ[x][mem+::cnt[x]-1]);
		}
	}
	if(ans==oo||m-ans<n*k){
		cout<<-1<<'\n';
		return 0;
	}
	cout<<ans<<'\n';
	for(int i=0;i<ansi%k;++i)
		cout<<i+1<<' ';
	int rest=ans-ansi%k;
	for(int i=ansi;i<ansj;++i){
		if(cnt[a[i]]==0&&rest>0){
			cout<<i+1<<' ';
			--rest;
		}
		if(cnt[a[i]])
			--cnt[a[i]];
	}
	cout<<'\n';
	return 0;
}