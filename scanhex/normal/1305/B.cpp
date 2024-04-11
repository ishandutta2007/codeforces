#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	vector<vector<int>>ans;
	vector<bool>mem(s.size());
	while(s.size()){
		vector<int>kek;
		int p=0,q=s.size()-1;
		while(p<q){
			if (mem[p]||s[p] == ')'){
				 ++p;
				 continue;
			}
			if (mem[q]||s[q] == '('){
				 --q;
				 continue;
			}
			kek.push_back(p);
			kek.push_back(q);
			mem[p]=mem[q]=true;
			++p;
			--q;
		}
		if (!kek.size())break;
		sort(kek.begin(),kek.end());
		ans.push_back(kek);
	}
	cout<<ans.size()<<'\n';
	for(auto&x:ans){
		cout<<x.size()<<'\n';
		 for(auto&y:x)
			 cout<<y+1<<' ';
		 cout<<'\n';
	}
	return 0;
}