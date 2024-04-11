#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
char c[210],l[30],r[30],vis[30]; 

int main()
{
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		memset(l,-1,sizeof(l));
		memset(r,-1,sizeof(r));
		memset(vis,0,sizeof(vis));
		scanf("%s",c+1);
		int n = strlen(c+1);
		int flag=0;
		for(int i=1;i < n;i++){
			if(l[c[i]-'a'] != c[i+1]-'a' && r[c[i]-'a'] != c[i+1]-'a'){
				if(r[c[i]-'a'] != -1 || r[c[i+1]-'a'] != -1){
					puts("NO");
					flag = 1;
					break;
				}
				if(l[c[i]-'a'] == -1)
					l[c[i]-'a'] = c[i+1]-'a';
				else
					r[c[i]-'a'] = c[i+1]-'a';
				if(l[c[i+1]-'a'] == -1)
					l[c[i+1]-'a'] = c[i]-'a';
				else
					r[c[i+1]-'a'] = c[i]-'a';
			}
		}
		if(flag)
			continue;
		int f = 0;
			for(int i=0;i <= 25;i++){
				int x = i;
				if(r[x] != -1){
					x = r[x];
					int las = i,lass;
					while(r[x] != -1 && x != i){
						lass = x;
						x = l[x] == las ? r[x] : l[x];
						las = lass;
					}
					if(x == i){
						puts("NO") , f = 1;
						break;
					}
				}
			}
			if(!f){
				puts("YES");
				for(int i=0;i <= 25;i++){
					if(!vis[i] && r[i] == -1){
						int x = i,las = i,lass;
						printf("%c",x+'a');
						vis[x] = 1;
						if(l[x] != -1){
						
						x = l[x];
						while(r[x] != -1){
							printf("%c",x+'a');
							vis[x] = 1;
							lass = x;
							x = l[x] == las ? r[x] : l[x];
							las = lass;
						}
						printf("%c",x+'a');
						vis[x] = 1;
						
						}
					}
				}
				puts("");
			}
		
	}
}