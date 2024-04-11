#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=1100;
vector<int>g[N];
set<int>l;

int deg[N];
int de[N];
bool used[N];
void d(int u){
	used[u]=true;
	for(int v:g[u]){
		if (used[v]){
			continue;
		}
		de[v]=de[u]+1;
		d(v);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;++i){
		 int a,b;
		 cin>>a>>b;
		 --a,--b;
		 g[a].push_back(b);
		 g[b].push_back(a);
		 deg[a]++;
		 deg[b]++;
	}
	for(int i=0;i<n;++i)
		if(deg[i]==1)
			l.insert(i);
	vector<bool>used(n);
	int cnt=0;
	while(2*cnt+1<n){
		++cnt;
		int a=*l.begin();
		l.erase(l.begin());
		int b=*l.begin();
		l.erase(l.begin());
		used[a]=used[b]=true;
		cout<<"? "<<a+1<<' '<<b+1<<endl;
		int x;
		cin>>x;
		if(x == a+1 || x== b + 1){
			cout<<"! "<< x<<endl;
			return 0;
		}
		for(int kek:g[a])
			if(--deg[kek]==1){
				l.insert(kek);
			}
		for(int kek:g[b])
			if(--deg[kek]==1){
				l.insert(kek);
			}
	}
	for(int i=0;i<n;++i)
		if(!used[i])
			cout<<"! "<<i+1<<endl;
	return 0;
}