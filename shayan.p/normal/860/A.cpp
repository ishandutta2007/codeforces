// Believe in yourself...
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
void print(vector<char>&v){
	for(ll i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<" ";
}
int main(){
	set<char>vol,used;
	ll num=0;
	vol.insert('a');vol.insert('e');vol.insert('i');vol.insert('o');vol.insert('u');
	string s;cin>>s;
	vector<char>str;
	for(ll i=0;i<s.size();i++){
		if(!vol.count(s[i])){
			used.insert(s[i]);
			num++;
		}
		else{
			used.clear();
			num=0;
		}
		if(num>2&&used.size()>1){
			print(str);
			str.clear();
			used.clear();
			num=1;
			used.insert(s[i]);
		}
		str.PB(s[i]);
	}
	print(str);
}