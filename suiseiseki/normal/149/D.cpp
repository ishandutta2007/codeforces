#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 700
#define Mod 1000000007
char s[Maxn+5];
int f[Maxn+5][Maxn+5][3][3];
int match[Maxn+5];
int n;
stack<int> st;
int dfs(int left,int right,int a,int b){
	if(f[left][right][a][b]!=-1){
		return f[left][right][a][b];
	}
	int& ans=f[left][right][a][b];
	ans=0;
	if(left>right){
		return ans=1;
	}
	if(match[left]==right){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==0&&j==0){
					continue;
				}
				if(i!=0&&j!=0){
					continue;
				}
				if(i!=0&&i==a){
					continue;
				}
				if(j!=0&&j==b){
					continue;
				}
				ans+=dfs(left+1,right-1,i,j);
				ans%=Mod;
			}
		}
		return ans;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==0&&j==0){
				continue;
			}
			if(i!=0&&j!=0){
				continue;
			}
			if(i!=0&&i==a){
				continue;
			}
			ans+=(int)((long long)dfs(left+1,match[left]-1,i,j)*dfs(match[left]+1,right,j,b)%Mod);
			ans%=Mod;
		}
	}
	return ans;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	for(int i=1;i<=n;i++){
		if(s[i]=='('){
			st.push(i);
		}
		else{
			match[st.top()]=i;
			st.pop();
		}
	}
	memset(f,-1,sizeof f);
	printf("%d\n",dfs(1,n,0,0));
	return 0;
}