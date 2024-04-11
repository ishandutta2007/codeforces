#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s[105];
bool cmp(string p,string q){
	if(p.size()==q.size()){
		return p<q;
	}
	return p.size()<q.size();
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n,cmp);
	bool yes=1;
	for(int i=1;i<n;i++){
		if(s[i+1].find(s[i])==(string::npos)){
			yes=0;
			break;
		}
	}
	if(!yes){
		puts("NO");
	}
	else{
		puts("YES");
		for(int i=1;i<=n;i++){
			cout<<s[i]<<endl;
		}
	}
	return 0;
}