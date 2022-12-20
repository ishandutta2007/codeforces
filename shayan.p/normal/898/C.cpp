#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
map<string,set<string> >mp;
bool no[500];
bool suf(string &s1,string &s2){
	if(s1.size()<s2.size())return 0;
	ll dif=s1.size()-s2.size();
	for(ll i=0;i<s2.size();i++){
		if(s2[i]!=s1[i+dif])
			return 0;
	}
	return 1;
}
vector<string> uniq(vector<string>&v){
	memset(no,0,sizeof no);
	for(ll i=0;i<v.size();i++){
		for(ll j=0;j<v.size();j++){
			if(i==j)continue;
			if(suf(v[i],v[j])){
				no[j]=1;
			}
		}
	}
	vector<string>vec;
	for(ll i=0;i<v.size();i++){
		if(!no[i]){
			vec.PB(v[i]);
		}
	}
	return vec;
}
int main(){
	ll n;cin>>n;
	for(ll i=0;i<n;i++){
		string name;cin>>name;
		ll t;cin>>t;
		for(ll j=0;j<t;j++){
			string number;cin>>number;
			mp[name].insert(number);
		}
	}
	cout<<mp.size()<<endl;
	for(map<string,set<string> >::iterator it=mp.begin();it!=mp.end();it++){
		set<string>st=(it->S);
		vector<string>vec;
		vec.clear();
		for(set<string>::iterator its=st.begin();its!=st.end();its++)
			vec.PB(*its);
		vector<string>v=uniq(vec);
		cout<<(it->F)<<" "<<v.size()<<" ";for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
	}
}