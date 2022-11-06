//By:Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int l = s.length();
	for(int i=l-1;i>=0;i--) {
		if(s[i] == '/') --l;
		else break;
	}
//	printf("%d\n", l);
	if(l == 0) {
	    puts("/");
	    return 0;
	}
	if(l == 1) {
	    cout<<s[0]<<endl;
	    return 0;
	}
	for(int i=0;i<l-1;i++) if(s[i] != '/' || s[i+1] != '/') cout<<s[i];
	if(s[l-1] != '/') cout<<s[l-1]<<endl;
	else cout<<endl;
	return 0;
}