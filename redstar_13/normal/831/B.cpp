#include <bits/stdc++.h>
using namespace std;
char s[100],t[100],w[1010];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	gets(s),gets(t),gets(w);
	int lena=strlen(s);
	int lenc=strlen(w);
	for(int i=0;i<lenc;i++){
		char k=w[i];
		if(k>='A' and k<='Z'){
			for(int j=0;j<lena;j++){
				if(k+32==s[j])w[i]=t[j]-32;
			}
		}
		else if(k>='a' and k<='z'){
			for(int j=0;j<lena;j++){
				if(k==s[j]) w[i]=t[j];
			}
		}
	}
		
	cout<<w;
	

	
	return 0;
}