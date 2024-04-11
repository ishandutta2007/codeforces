#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int t;
bool vis[26];
char ch[MN],T[MN],S[MN];
int nex[MN][26];
int main(){
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%s%s",ch+1,T+1);
		int l2=strlen(ch+1),l1=strlen(T+1);
		memset(vis,0,sizeof(vis));
		for(int i='a';i<='z';++i)nex[l2+1][i-'a']=l2+1;
		for(int i=l2;i;--i){
			for(int j=0;j<26;++j)
				nex[i][j]=nex[i+1][j];
			nex[i][ch[i]-'a']=i;
			vis[ch[i]-'a']=1;
		}
		int now=1,ans=1,op=1;
		for(int i=1;i<=l1;++i){
			if(!vis[T[i]-'a']) {puts("-1");op=0;break;}
			now=nex[now][T[i]-'a']+1;
			if(now==l2+2){ans++;now=nex[1][T[i]-'a']+1;}
	//		if(i==l1)cerr<<"???? "<<T[i]<<" "<<now<<endl;
		}
		if(op)printf("%d\n",ans);
	}
}