//In the name of God
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int Maxn = 2015;
bool mark[Maxn][Maxn];
pair<int,int> Que[Maxn * Maxn];
char S[Maxn][Maxn];
pair<int,int> par[Maxn][Maxn];
int ans[Maxn * Maxn];
int bg,ed;
int n,m;
bool check(int i,int j){
	if(i >= n || j >= m || j < 0 || i < 0)
		return 0;
	return 1;
}
pair<int,int> find(pair<int,int> v){
	if(v != par[v.first][v.second])
		return par[v.first][v.second] = find(par[v.first][v.second]);
	return v;
}
void unite(pair<int,int> u,pair<int,int> v){
	u = find(u),v = find(v);
	par[u.first][u.second] = v;
	return;
}
bool cons(int i,int j){
	int Max = 0;
	for(int r = -1; r < 2;r++)
		for(int l = -1;l < 2;l++){
			if(abs(r + l) != 1)
				continue;
			int x = r + i,y = l + j;
			if(check(x,y) && S[x][y] != '*'){
				pair<int,int> save = find(make_pair(x,y));
				Max = max(++ans[save.first * m + save.second],Max);
			}
		}
	for(int r = -1; r < 2;r++)
		for(int l = -1;l < 2;l++){
			if(abs(r + l) != 1)
				continue;
			int x = r + i,y = l + j;
			if(check(x,y) && S[x][y] != '*'){
				pair<int,int> save = find(make_pair(x,y));
				ans[save.first * m + save.second] = 0;
			}
		}
	if(Max >= 2)
		return 1;
	return 0;
}
void update(pair<int,int> v){
	int i = v.first,j = v.second;
	for(int r = -1; r < 2;r++)
		for(int l = -1; l < 2;l++){
			if(abs(r + l) != 1)
				continue;
			int x = r + i,y = l + j;
			if(check(x,y) && S[x][y] != '*')
				unite(v,make_pair(x,y));
		}
	for(int r = -1;r < 2;r++)
		for(int l = -1;l < 2;l++){
	//		if(abs(r + l) != 1)
	//			continue;
			int x = r + i,y = l + j;
			if(check(x,y) && S[x][y] == '*')
				if(!mark[x][y] && cons(x,y)){
					Que[ed++] = make_pair(x,y);
					S[x][y] = '.';
					mark[x][y] = 1;
				}
		}
	return;
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < n;i++)
		scanf("%s",&S[i]);
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++)
			par[i][j] = make_pair(i,j);
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			if(S[i][j] == '.')
				update(make_pair(i,j));
		}
	}
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++)
			if(S[i][j] == '*' && cons(i,j)){
				S[i][j] = '.';
				mark[i][j] = 1;
				Que[ed++] = make_pair(i,j);
			}
	while(bg != ed){
		pair<int,int> v = Que[bg++];
		int i = v.first,j = v.second;
		update(v);
	}
	for(int i = 0; i < n;i++){
			printf("%s",S[i]);
		printf("\n");
	}
	return 0;
}