#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,cx=0,ans=0;
	cin>>n;
	string s;
	cin>>s;
	for(string::iterator it=s.begin(); it!=s.end(); it++){
		if(*it=='x') cx++;
		else cx=0;
		if(cx>=3) ans++;
	}
	cout << ans << '\n';
	return 0;
}