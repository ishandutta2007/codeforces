#include <bits/stdc++.h>

const int max_N = 121;

int sg[max_N][max_N][26];

std::vector<std::pair<int,int>>vec[max_N];

int SG(int x,int y,int w){
	if(~sg[x][y][w])return sg[x][y][w];
	std::vector<int>mex;
	for(auto&e:vec[x])
		if(e.second>=w){
			mex.push_back(SG(y,e.first,e.second));
		}
	std::sort(mex.begin(),mex.end());
	mex.erase(std::unique(mex.begin(),mex.end()),mex.end());
	int i=0;
	for(;i<(int)mex.size()&&mex[i]==i;++i);
	return sg[x][y][w]=i;
}

int n,m;

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v; char w[5];
		scanf("%d%d%s",&u,&v,w);
		vec[u].push_back({v,w[0]-'a'});
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<26;++k){
				sg[i][j][k]=-1;
			}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			putchar(SG(i,j,0)?'A':'B');
		}
		puts("");
	}
	return 0;	
}