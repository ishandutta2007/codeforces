#include <bits/stdc++.h>
using namespace std;

string a,b,c;

int main(){
	cin>>a>>b;
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	if(a.size()<b.size()){
		cout<<a<<endl;
		return 0;
	}
	for(int i=0;i<b.size();i++){
		for(int i=0;i<a.size();i++){
			string e=a.substr(0,i)+a.substr(i+1);
			sort(e.begin(),e.end());
			string d=c+a[i]+e;
			if(d<=b){
				c+=a[i];
				a.erase(i,1);
				break;
			}
		}
	}
	cout<<c<<endl;
	return 0;
}