#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
int change[30];
int main(){
	string s1,s2;cin>>s1>>s2;
	for(ll i=0;i<26;i++){
		change[s1[i]-'a']=s2[i]-'a';
	}
	string s;cin>>s;
	for(ll i=0;i<s.size();i++){
		if('a'<=s[i]&&s[i]<='z'){
			cout<<char(change[s[i]-'a']+'a');
		}
		else if('A'<=s[i]&&s[i]<='Z'){
			cout<<char(change[s[i]-'A']+'A');
		}
		else cout<<s[i];
	}
}