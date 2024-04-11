#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>bits;
	for(int i=0;i<6;++i)
		bits.push_back(n&1),n>>=1;
	vector<int>bits1={bits[4],bits[1],bits[3],bits[2],bits[0],bits[5]};
	int ans=0;
	for(int i=0;i<6;++i){
		ans+=bits1[i] << i;
	}
	cout<<ans<<'\n';
	return 0;
	vector<pair<int,int>>t={{2,2},{5,24},{35,50}};
	vector<int>perm(6);
	iota(perm.begin(),perm.end(),0);
	do{
		bool bad=false;
		for(auto[in,out]:t){
			vector<int>bin,bout;
			for(int i=0;i<6;++i)
				bin.push_back(in&1),in>>=1;
			for(int i=0;i<6;++i)
				bout.push_back(out&1),out>>=1;
			vector<int>bin1={bin[perm[0]],bin[perm[1]],bin[perm[2]],bin[perm[3]],bin[perm[4]],bin[perm[5]]};
			if (bin1 != bout)
				bad=true;
		}
		if (!bad){
			for(int x:perm)
				cout << x <<' ';
			cout<<'\n';
		}

	}
	while(next_permutation(perm.begin(),perm.end()));
	return 0;
}