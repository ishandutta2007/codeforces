#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,l,r,it;
char s[1050];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s+1;
		n=strlen(s+1);
		l=1;r=n;it=n-1+'a';
		while(l<=r){
			if(s[l]==it){
				l++;it--;continue;
			}
			if(s[r]==it){
				r--;it--;continue;
			}
			cout<<"NO"<<endl;goto aaa;
		}
		cout<<"YES"<<endl;
		aaa:;
	}
}