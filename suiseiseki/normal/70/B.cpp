#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
const int N=1e4+5;
char c[N];
int n,m=1,ans;
vector<int>v;
inline bool _end(char h){
	return (h=='?'||h=='.'||h=='!');
}
int main(){
	cin>>n;
	gets(c);
	gets(c);
	for(int i=0;i<(int)strlen(c);i++){
		if(!_end(c[i])){
			m++;
		}
		else{
			v.push_back(m);
			if(m>n){
				cout<<"Impossible"<<endl;
				return 0;
			}
			m=0;
		}
	}
	for(int i=0;i<(int)v.size();i++){
		if(m+v[i]+1<=n&&m>0){
			m+=v[i]+1;
		}
		else{
			m=0;
			ans++;
			m=v[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}