#include<bits/stdc++.h>

using namespace std;
using nagai=long long;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		 string s;cin>>s;
		 int kek=*max_element(s.begin(),s.end());
		 int mem=*min_element(s.begin(),s.end());
		 set<char>ss(s.begin(),s.end());
		 if(ss.size()==s.size()&&(int)s.size()==kek-mem+1)
			 cout<<"Yes\n";
		 else
			 cout<<"No\n";
	}
}