#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[10000],n,r,T;
void work(){
	r=0,cin>>n>>s,t=s,sort(t.begin(),t.end());
	for(int i=0;i<n;++i)if(s[i]!=t[i])r++;
	cout<<r<<'\n';
}
int main(){
	for(cin>>T;T--;)work();
}