#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=n;i>=N;i--)
#define fi first
#define se second
map<char,char> key;
char x[27],y[27];
string s;
int main(){
	rep(i,1,26)cin>>x[i];
	rep(i,1,26){
		cin>>y[i];
		key[x[i]]=y[i];
		key[x[i]-' ']=y[i]-' ';
	}
	cin>>s;
	rep(i,0,s.size()-1){
		if(s[i]<58)cout<<s[i];
		else cout<<key[s[i]];
	}
	cout<<endl;
}