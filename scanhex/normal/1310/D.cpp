#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=100;
int matr[N][N];

const int K=12;
int de[N][K];
const int oo=0x3f3f3f3f;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>matr[i][j];
	int ans=oo;
	for(int i=0;i<30000;++i){
		memset(de,0x3f,sizeof de);
		vector<int>col(n);
		for(int i=0;i<n;++i)
			col[i]=rnd()%2;
		de[0][0]=0;
		for(int l=0;l<k;++l)
			for(int a=0;a<n;++a)
				for(int b=0;b<n;++b)
					if (col[a]!=col[b])
						de[b][l+1]=min(de[b][l+1],de[a][l]+matr[a][b]);
		ans=min(ans,de[0][k]);
	}
	cout<<ans<<'\n';
	return 0;
}