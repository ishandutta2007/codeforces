#include<bits/stdc++.h>
using namespace std;
char ch[500005];
int vis[26];
signed main(){
	scanf("%s",ch);
	int ln=strlen(ch);
	for(int i=0;i<ln;++i){
		vis[ch[i]-'a']++;
		bool t=0;
		for(int j=0;j<ch[i]-'a';++j)
			if(vis[j]){
				puts("Ann");
				t=1;
				break;
			}
			
		if(!t) puts("Mike");
	}
	return 0;
}