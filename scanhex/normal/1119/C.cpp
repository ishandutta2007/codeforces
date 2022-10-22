#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=505;
int n,m;
int matr1[N][N],matr2[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>matr1[i][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			cin>>matr2[i][j];
		}
	for(int i=0;i<n;++i){
		int x=0;
		for(int j=0;j<m;++j){
			x^=matr1[i][j];
			x^=matr2[i][j];
		}
		if(x==1){
			 cout<<"No\n";
			 return 0;
		}
	}
	for(int i=0;i<m;++i){
		int x=0;
		for(int j=0;j<n;++j){
			x^=matr1[j][i];
			x^=matr2[j][i];
		}
		if(x==1){
			 cout<<"No\n";
			 return 0;
		}
	}
	cout<<"Yes\n";

	return 0;
}