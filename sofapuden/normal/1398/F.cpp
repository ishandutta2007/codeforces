#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	s+='$';
	vector<int> pre;
	int l = 0;
	int ls = 0;
	char lst = '$';
	for(int i = 0; i < n; ++i){
		if(s[i] == '?')continue;
		if(lst == s[i] || lst == '$'){
			for(;ls < i; ls++)s[ls] = s[i];
		}
		ls = i+1;
		lst = s[i];
	}
	while(l < n){
		int cn = 0;
		while(s[l] =='?')cn++, l++;
		pre.push_back(cn);
		cn = 0;
		while(s[l] == '0')cn++, l++;
		pre.push_back(cn);
		cn = 0;
		while(s[l] == '?')cn++, l++;
		pre.push_back(cn);
		cn = 0;
		while(s[l] == '1')cn++, l++;
		pre.push_back(cn);
	}
	pre.push_back(0);
	vector<int> ans(n+1,0);
	vector<int> lst1 = {0};
	vector<int> lst2 = {0};
	for(int i = 1; i < (int)pre.size(); i+=2){
		for(int j = 1; j <= pre[i-1]+pre[i]+pre[i+1]; ++j){
			int mx = pre[i]+pre[i+1];
			if((int)lst1.size() <= j){
				mx+=pre[i-1];
			}
			else{
				mx+=lst1[j];
			}
			ans[j]+=mx/j;
			lst2.push_back(min(mx%j,pre[i+1]));
		}
		swap(lst1,lst2);
		lst2 = {0};
	}
	for(int i = 1; i <= n; ++i)cout << ans[i] << ' ';
	cout << '\n';
}