#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
string s;
long long a;
int main(){
	cin>>s;
	a=s.size();
	rep(i,a)cout<<s[i];
	rep(i,a)cout<<s[a-i-1];
	cout<<endl;
	return 0;
}