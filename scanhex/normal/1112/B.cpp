#include<bits/stdc++.h>
using namespace std;
using nagai=long long;
#define sz(x) (int)(x.size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	vector<int>cur(k,-1);
	vector<int>beg(k,-1);
	for(auto&x:a)cin>>x;
	int MX=150150;
	int cnt=0;
	int ptr=0;
	queue<int>svob;
	for(int i=0;i<k;++i)
		svob.push(i);
	vector<bool>good(n);
	for(int t=0;t<MX;++t){
		while(ptr<n&&svob.size()){
			int x=svob.front();
			cur[x]=ptr++;
			beg[x]=t;
			svob.pop();
		}
		int perc=round(100.0*cnt/n);
		for(int i=0;i<k;++i){
			if(perc>0&&cur[i]!=-1&&t-beg[i]==perc){
//				cerr<<t<<' '<<cur[i]<<'\n';
				good[cur[i]]=true;
			}
		}
		for(int i=0;i<k;++i){
			if(cur[i]!=-1&&t-beg[i]==a[cur[i]]){
				++cnt,svob.push(i),cur[i]=-1;
			}
		}
		if(cnt==n)
			break;
		while(ptr<n&&svob.size()){
			int x=svob.front();
			cur[x]=ptr++;
			beg[x]=t;
			svob.pop();
		}
	}
	cout<<count(good.begin(),good.end(),true)<<'\n';
	return 0;
}