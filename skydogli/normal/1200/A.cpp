#include<bits/stdc++.h>
using namespace std;
int n,vis[15];
char ch[100005];
int main(){
	scanf("%d",&n);
	scanf("%s",ch+1);
	for(int i=1;i<=n;++i){
		if(ch[i]=='L'){
			for(int i=1;i<=10;++i)
				if(!vis[i]){
					vis[i]=1;
					break;
				}
		}
		else if(ch[i]=='R'){
			for(int i=10;i;--i)
				if(!vis[i]){
					vis[i]=1;
					break;
				}
		}
		else vis[ch[i]-'0'+1]=0;
	}
	for(int i=1;i<=10;++i)cout<<vis[i];
	return 0;
}