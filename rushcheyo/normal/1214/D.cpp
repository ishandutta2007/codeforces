#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen(int l,int r){
	return uniform_int_distribution<int>(l,r)(rng);
}

bool prime(int x){
	for(int i=3;i*i<=x;i+=2)if(x%i==0)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<string> v(n);
	for(int i=0;i<n;++i)cin>>v[i];
	int P;
	do P=gen(250000000,500000000)*2+1;while(!prime(P));
	vector<vector<int>> f(n,vector<int>(m)),g(n,vector<int>(m));
	f[0][0]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			if(v[i][j]=='#')continue;
			if(i)f[i][j]=(f[i-1][j]+f[i][j])%P;
			if(j)f[i][j]=(f[i][j-1]+f[i][j])%P;
		}
	if(!f[n-1][m-1])puts("0");
	else{
		g[n-1][m-1]=1;
		for(int i=n-1;i>=0;--i)
			for(int j=m-1;j>=0;--j){
				if(v[i][j]=='#')continue;
				if(i+1<n)g[i][j]=(g[i+1][j]+g[i][j])%P;
				if(j+1<m)g[i][j]=(g[i][j+1]+g[i][j])%P;
			}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if(i==0&&j==0)continue;
				if(i==n-1&&j==m-1)continue;
				if(1LL*f[i][j]*g[i][j]%P==f[n-1][m-1])
					return puts("1"),0;
			}
		puts("2");
	}
}