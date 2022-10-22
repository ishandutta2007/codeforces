
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int n;
char a[100010],b[100010];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		vector<int>pos[30];
		bool flag=0;
		int ans=0;
		for(int i=1;i<=n;++i) if(b[i]<a[i]) flag=1;
		if(flag){
			printf("-1\n");continue ;
		}
		for(int i=1;i<=n;++i) pos[a[i]-'a'+1].push_back(i);
		for(int i=1;i<=20;++i){
			int v=50;
			for(int j=0;j<pos[i].size();++j){
				if(b[pos[i][j]]-'a'+1>i) v=min(v,b[pos[i][j]]-'a'+1-i);
			}
			if(v<50) ++ans;
			for(int j=0;j<pos[i].size();++j) if(b[pos[i][j]]-'a'+1>i) pos[i+v].push_back(pos[i][j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}