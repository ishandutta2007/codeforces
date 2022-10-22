#include<bits/stdc++.h>
using namespace std;
int T,n,tag[200005],num[200005];
char ch[200015];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,&ch);
		for(int i=0;i<10;++i){
			int vis=0;
			for(int j=0;j<n;++j){
				if(ch[j]-'0'<i||(ch[j]-'0'==i&&vis)){
					tag[j]=1;
				}
				else {
					tag[j]=2;
					if(!vis&&ch[j]-'0'>i) vis=1;
				}
			}	
			int cnt=0;
			for(int j=0;j<n;++j)
				if(tag[j]==1) num[++cnt]=ch[j];
			for(int j=0;j<n;++j)
				if(tag[j]==2) num[++cnt]=ch[j];
			bool ok=0;
			for(int j=1;j<cnt;++j)
				if(num[j]>num[j+1])ok=1;
			if(!ok) {
				for(int j=0;j<n;++j){
					putchar(tag[j]+'0');
				}
				puts("");
				break;
			}
			else if(i==9) puts("-");
		}
	}
	return 0;
}