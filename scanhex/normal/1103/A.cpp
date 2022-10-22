#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	bool occv=false, occh=false;
	for(auto& x:s){
		if(x=='0'){
			if(occv)
				cout<<"3 4\n";
			else
				cout<<"1 4\n";
			occv=!occv;
		} else {
			if (occh)
				cout<<"4 3\n";
			else
				cout<<"4 1\n";
			occh=!occh;
		}
	}
	return 0;
}