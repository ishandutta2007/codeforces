#include <bits/stdc++.h>
using namespace std;
int main(){
	char s[1005];
	scanf("%s",s);
	int l=strlen(s);
	bool change=true;
	for(int i=1;i<l;i++) if(s[i]>='a'){
		change=false;
		break;
	}
	if(change)  for(int i=0;i<l;i++) if(s[i]>='A' and s[i]<='Z') s[i]+=32; else s[i]-=32;
	puts(s);
	return 0;
}