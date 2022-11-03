#include<bits/stdc++.h>
using namespace std;

int T;
bool v[35],u[35];
char b[5],s[100005];
bool f=0;
int main(){
	scanf("%d",&T);
	for(int i=0;i<26;i++)v[i]=1;
	int ans=0;
	for(int i=0;i<T;i++){
		scanf("%s%s",b,s);
		if(b[0]=='.'){
			int m=strlen(s);
			for(int j=0;j<m;j++)v[s[j]-'a']=0;
		}else if(b[0]=='!'){
			if(f)ans++;
			else{
				memset(u,0,sizeof(u));
				int m=strlen(s);
				for(int j=0;j<m;j++)u[s[j]-'a']=1;
				for(int j=0;j<26;j++)if(!u[j])v[j]=0;
			}
		}else{
			if(f){
				if(!v[s[0]-'a'])ans++;
			}else{
				v[s[0]-'a']=0;
			}
		}
		int s=0;
		for(int i=0;i<26;i++)s+=v[i];
//		printf("%d\n",s);
		f=s==1;
	}
	printf("%d\n",ans);
	return 0;
}