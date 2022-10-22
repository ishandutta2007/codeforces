#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=300300;
int n;
int s[N];
int t[N];
struct chel{
	int f,t,i;
	bool operator <(chel b)const {
		if(f!=b.f)
			return f<b.f;
		return i<b.i;
	}
};
void fail(){
	 cout<<"NO\n";
	 exit(0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>s[i];
	for(int i=0;i<n;++i)
		cin>>t[i];
	nagai s1=accumulate(s,s+n,0LL);
	nagai s2=accumulate(t,t+n,0LL);
	if(s1!=s2){
		fail();
	}
	sort(t,t+n);
	vector<int>ord(n);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int a,int b){
			 return s[a]<s[b];
			});
	vector<pair<int,int>>st;
	vector<chel>ans;
	for(int i=0;i<n;++i){
		int a=s[ord[i]],b=t[i];
		if(b>=a)
			st.emplace_back(b-a,ord[i]);
		else{
			int rest=a-b;
			while(st.size()){
				ans.push_back({st.back().second,ord[i],min(rest,st.back().first)});
				if(st.back().first<=rest){
					rest-=ans.back().i;
					st.pop_back();
				}
				else{
					st.back().first-=rest;
					rest-=ans.back().i;
					break;
				}
			}
			if(rest)fail();
		}
	}
	cout<<"YES\n";
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x.f+1<<' '<<x.t+1<<' '<<x.i<<'\n';
	}
	return 0;
}