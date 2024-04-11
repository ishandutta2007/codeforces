#include <bits/stdc++.h>



#define NN 555

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;

typedef pair<int, pii> pi3;



char s[NN][NN];

int flag[NN][NN], vst[NN][NN];



int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

int n,m;

int nn=0;

pi3 ans[1000000];



void dfs(pii u, pii fa){

	int x=u.first, y=u.second;

	vst[x][y]=1;

	for(int i=0; i<4; i++){

		int xx=x+dx[i], yy=y+dy[i];

		if(xx<0 || yy<0 || xx>=n || yy>=m) continue;

		if(s[xx][yy]=='#' || vst[xx][yy]) continue;

		

		dfs(pii(xx, yy), pii(x, y));

	}

	

	int q=fa.first, w=fa.second;

	if(fa!=pii(-1, -1)) {

		ans[nn].first=0;

		ans[nn].second.first=x+1;

		ans[nn].second.second=y+1;

		nn++;

		ans[nn].first=2;

		ans[nn].second.first=x+1;

		ans[nn].second.second=y+1;

		nn++;

	}

}



int main() {

	cin>>n>>m;

	int i,j;

	

	for(i=0; i<n; i++){

		scanf("%s", s[i]);

	}

	for(i=0; i<n; i++){

		for(j=0; j<m; j++){

			if(s[i][j]=='#') continue;

			ans[nn].first=1;

			ans[nn].second.first=i+1;

			ans[nn].second.second=j+1;

			nn++;

		}

	}

	

	for(i=0; i<n; i++){

		for(j=0; j<m; j++){

			if(vst[i][j]) continue;

			if(s[i][j]=='.') dfs(pii(i, j), pii(-1, -1));

		}

	}

	

	cout<<nn<<endl;

	for(i=0; i<nn; i++){

		int flag=ans[i].first;

		if(flag==0) printf("D ");

		if(flag==1) printf("B ");

		if(flag==2) printf("R ");

		printf("%d %d\n", ans[i].second.first, ans[i].second.second);

	}

	return 0;

}