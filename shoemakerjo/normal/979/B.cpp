#include <bits/stdc++.h>
using namespace std;

int work(string s,int n){
	map<char,int> cnt;
	for(char c:s)cnt[c]++;
	int mx=0;
	for(auto it:cnt)mx=max(mx,it.second);
	if(mx==s.size() && n==1) return s.size()-1;
	return min(mx+n,(int)s.size());
}

int main(){
	int n;
	cin>>n;
	string a[3];
	cin>>a[0]>>a[1]>>a[2];
	int val[3];
	for(int i=0;i<3;i++)val[i]=work(a[i],n);
	int mx=max({val[0],val[1],val[2]});
	int cnt=0;
	for(int i=0;i<3;i++)if(val[i]==mx)cnt++;
	string s[3]={"Kuro","Shiro","Katie"};
	if(cnt>1)cout<<"Draw"<<endl;
	else{
		for(int i=0;i<3;i++)if(val[i]==mx){
			cout<<s[i]<<endl;
		}
	}
	return 0;
}