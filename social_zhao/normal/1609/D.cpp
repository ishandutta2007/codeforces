#include<bits/stdc++.h>
//#define int long long
const int N=1005;
using namespace std;

int rst,n,d;
int fa[N],sz[N];
multiset<int> s;

int gf(int k){
	return k==fa[k] ? k:fa[k]=gf(fa[k]);
}

void print(){
	int ans=0;
	auto s1=s;
	for(int i=0;i<=rst&&!s1.empty();i++)
		ans+=*s1.rbegin(),s1.erase(--s1.end());
	cout<<ans-1<<endl;
} 

int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		fa[i]=i,sz[i]=1,s.insert(1);
	for(int i=1;i<=d;i++){
		int x,y;cin>>x>>y;
		int fx=gf(x),fy=gf(y);
		if(fx!=fy)
			fa[fx]=fy,s.erase(s.lower_bound(sz[fx])),s.erase(s.lower_bound(sz[fy])),sz[fy]+=sz[fx],s.insert(sz[fy]);
		else rst++;
		print();
	}
}