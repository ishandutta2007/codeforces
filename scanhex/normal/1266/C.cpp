#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

nagai gcd(nagai a,nagai b){
	while(b)
		a%=b,swap(a,b);
	return a;
}

int n,m;
bool check(nagai M, bool print=false){
	vector<nagai>cur;
	for(int i=M;i>1;--i){
		bool ok=true;
		for(auto&x:cur)
			if(gcd(i,x)>1){
				ok=false;
				break;
			}
		if(ok)cur.push_back(i);
		if(cur.size()==n+m)break;
	}
	if(print){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				cout<<cur[i]*cur[n+j]<<' '; // TODO maybe
			cout<<'\n';
		}
	}
	return cur.size()==n+m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<int>arr(n+m);
	mt19937 rnd(228);
	iota(arr.begin(),arr.end(),1);
	for(int i=0;i<2000;++i){
		bool ok=true;
		shuffle(arr.begin(),arr.end(),rnd);
		vector<vector<int>>ans(n,vector<int>(m));
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				ans[i][j]=arr[i]*arr[n+j]/gcd(arr[i],arr[n+j]);
		set<int>st;
		for(int i=0;i<n;++i){
			 int kek=0;
			 for(int j=0;j<m;++j)
				 kek=gcd(kek,ans[i][j]);
			 st.insert(kek);
		}
		for(int i=0;i<m;++i){
			 int kek=0;
			 for(int j=0;j<n;++j)
				 kek=gcd(kek,ans[j][i]);
			 st.insert(kek);
		}
		if(st.size()==n+m){
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j)
					cout<<ans[i][j]<<' ';
				cout<<'\n';
			}
			return 0;
		}
	}
	cout<<0<<'\n';
	/*
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)
			cout<<(i+1)*(j+n+1)/gcd(i+1,j+n+1)<<' ';
		cout<<'\n';
	}
	*/
	return 0;
}