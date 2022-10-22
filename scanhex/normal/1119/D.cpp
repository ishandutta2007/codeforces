#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
const int N=100100;
int n;
nagai s[N];
const nagai oo=0x3f3f3f3f3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>s[i];
	sort(s,s+n);
	int q;
	cin>>q;
	vector<pair<nagai,int>>ques(q);
	for(int i=0;i<q;++i){
		nagai l,r;
		cin>>l>>r;
		l=r-l+1;
		ques[i]={l,i};
	}
	vector<nagai>mem;
	for(int i=0;i+1<n;++i)
		mem.push_back(s[i+1]-s[i]);
	mem.push_back(oo);
	sort(mem.begin(),mem.end());
	sort(ques.begin(),ques.end());
	nagai sum=0,ptr=0;
	vector<nagai>ans(q);
	for(auto x:ques){
		while(ptr<n&&mem[ptr]<=x.first)
			sum+=mem[ptr],++ptr;
		ans[x.second]=sum+(n-ptr)*x.first;
	}
	for(int i=0;i<q;++i)cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}