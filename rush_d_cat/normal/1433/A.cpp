#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
vector<string> v;
int main() {
	for(int i=1;i<=9;i++){
		for(int j=1;j<=4;j++){
			string ans="";
			for(int k=1;k<=j;k++){
				ans+=(i+'0');
			}
			v.push_back(ans);
		}
	}
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		int res=0;
		for(int i=0;i<v.size();i++){
			res+=v[i].length();
			if(s==v[i])break;
		}
		printf("%d\n", res);
	}
}