#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=100100;

int a[N];
int p[N];
int sz[N];
multiset<int>szs;
int getp(int x){
	 return p[x] == x? x : p[x]=getp(p[x]);
}
void unite(int a, int b){
	a=getp(a);
	b=getp(b);
	if(a==b)return;
	szs.erase(szs.find(sz[a]));
	szs.erase(szs.find(sz[b]));
	sz[a]+=sz[b];
	p[b]=a;
	szs.insert(sz[a]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	vector<int>ord(n);
	for(int i=0;i<n;++i){
		ord[i]=i;
	}
	iota(p,p+n+1,0);
	sort(ord.begin(),ord.end(),[&](int a,int b){
			 return ::a[a]<::a[b];
			});
	fill(sz,sz+n,1);
	int mx=-1,mxk=-1;
	for(int i=0;i<n;++i){
		 int j=i;
		 while(j<n&&a[ord[j]]==a[ord[i]])++j;
		 for(int k=i;k<j;++k){
			 int x=ord[k];
			 szs.insert(1);
			 if(x-1>=0&&a[x-1]<=a[x]){
				 unite(x-1,x);
			 }
			 if(x+1<n&&a[x+1]<=a[x])
				 unite(x,x+1);
		 }
		 if(szs.size()&&*szs.begin()==*szs.rbegin()){
			 if ((int)szs.size()>mx)
				 mx=szs.size(),mxk=a[ord[i]]+1;
		 }
		 i=j-1;
	}
	if (mx==1||mx==-1){
		cout<<a[ord[0]]+1<<'\n';
	}
	else
		cout<<mxk<<'\n';
	return 0;
}