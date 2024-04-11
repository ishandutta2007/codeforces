/*
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define ull unsigned long long
#define Mod 998244353
vector<string> mp;
vector<vector<ull> > f[2],g[2];
vector<ull> q;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		mp.push_back(s);
	}
	for(int i=0;i<m;i++){
		q.push_back(0);
	}
	for(int i=0;i<n;i++){
		f[0].push_back(q);
		g[0].push_back(q);
		f[1].push_back(q);
		g[1].push_back(q);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0){
				f[0][i][j]=1;
				f[1][i][j]=1;
				continue;
			}
			if(mp[i][j]=='#'){
				f[0][i][j]=0;
				f[1][i][j]=0;
				continue;
			}
			if(i>0){
				f[0][i][j]+=f[0][i-1][j];
				f[1][i][j]+=f[1][i-1][j];
				f[1][i][j]%=Mod;
			}
			if(j>0){
				f[0][i][j]+=f[0][i][j-1];
				f[1][i][j]+=f[1][i][j-1];
				f[1][i][j]%=Mod;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1&&j==m-1){
				g[0][i][j]=1;
				g[1][i][j]=1;
				continue;
			}
			if(mp[i][j]=='#'){
				g[0][i][j]=0;
				g[1][i][j]=0;
				continue;
			}
			if(i<n-1){
				g[0][i][j]+=g[0][i+1][j];
				g[1][i][j]+=g[0][i+1][j];
				g[1][i][j]%=Mod;
			}
			if(j<m-1){
				g[0][i][j]+=g[0][i][j+1];
				g[1][i][j]+=g[1][i][j+1];
				g[1][i][j]%=Mod;
			}
		}
	}
	if(f[0][n-1][m-1]==0&&f[1][n-1][m-1]==0){
		puts("0");
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[0][i][j]*g[0][i][j]==f[0][n-1][m-1]){
				ans++;
			}
		}
	}
	if(ans>2){
		puts("1");
	}
	else{
		puts("2");
	}
	return 0;
}
*/
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
vector<string> mp;
vector<vector<int> > nxt;
int n,m;
bool dfs(int x,int y){
	if(x>=n||y>=m){
		return 0;
	}
	if(x==n-1&&y==m-1){
		return 1;
	}
	if(mp[x][y]=='#'){
		return 0;
	}
	if(nxt[x][y]!=-1){
		return (nxt[x][y]!=-2);
	}
	nxt[x][y]=-2;
	if(dfs(x+1,y)){
		nxt[x][y]=0;
		return 1;
	}
	if(dfs(x,y+1)){
		nxt[x][y]=1;
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		mp.push_back(s);
		nxt.push_back(vector<int>());
		for(int j=0;j<m;j++){
			nxt[i].push_back(-1);
		}
	}
	if(!dfs(0,0)){
		puts("0");
		return 0;
	}
	for(int i=0,j=0;i!=n-1||j!=m-1;(nxt[i][j]?(j++):(i++))){
		mp[i][j]='#';
	}
	mp[0][0]='.';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			nxt[i][j]=-1;
		}
	}
	if(!dfs(0,0)){
		puts("1");
		return 0;
	}
	puts("2");
	return 0;
}