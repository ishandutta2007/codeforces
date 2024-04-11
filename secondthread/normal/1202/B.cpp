#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

string input;
const int n=10;
ll dist[n][n];

int solve(int a, int b) {
	const ll oo=1e15;
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
			dist[i][j]=oo;
	for (int from=0; from<n; from++) {
		dist[from][(from+a)%n]=1;
		dist[from][(from+b)%n]=1;
	}
	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
	ll total=0;
	for (int i=0; i+1<input.size(); i++) {
		int now=input[i]-'0', next=input[i+1]-'0';	
		if (total==-1||dist[now][next]>=oo)
			total=-1;
		else
			total+=dist[now][next]-1;
	}
	return total;
}

int main() {
	cin>>input;
	int ans[n][n];
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			ans[i][j]=ans[j][i]=solve(i, j);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cout<<ans[i][j]<<' ';
		cout<<'\n';
	}

	return 0;
}