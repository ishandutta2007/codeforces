#include <bits/stdc++.h>
using namespace std;
#define D if(false)

template<typename T>
void println(vector<T> v) {
	for (T t:v)
		D cout<<t<<' ';
	D cout<<'\n';
}


int main() {
	int n; cin>>n;
	vector<vector<int>> adj(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		string line; cin>>line;
		for (int j=0; j<n; j++)
			adj[i][j]=(line[j]=='1')?1:100000000;
	}
	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				adj[i][j]=min(adj[i][j], adj[i][k]+adj[k][j]);
	int m; cin>>m;
	vector<int> input(m);
	for (int i=0; i<m; i++) cin>>input[i];
	for (int i=0; i<m; i++) input[i]--;

	vector<int> distanceToFinish(m), nextTake(m);
	distanceToFinish[m-1]=1;
	nextTake[m-1]=-1;
	vector<int> lastSeen(n, -1);
	lastSeen[input[m-1]]=m-1;
	for (int indexToKeep=m-2; indexToKeep>=0; indexToKeep--) {
		distanceToFinish[indexToKeep]=1+distanceToFinish[indexToKeep+1];
		nextTake[indexToKeep]=indexToKeep+1;
		for (int goTo=0; goTo<n; goTo++) {
			if (goTo==input[indexToKeep]) continue;
			if (lastSeen[goTo]==-1) continue;
			if (lastSeen[goTo]-indexToKeep!=adj[input[indexToKeep]][goTo]) continue;
			if (distanceToFinish[indexToKeep]<=1+distanceToFinish[lastSeen[goTo]]) continue;
			distanceToFinish[indexToKeep]=1+distanceToFinish[lastSeen[goTo]];
			nextTake[indexToKeep]=lastSeen[goTo];		
		}
		lastSeen[input[indexToKeep]]=indexToKeep;
	}
	cout<<distanceToFinish[0]<<'\n';
	int node=0;
	while (node!=-1) {
		cout<<input[node]+1<<" ";
		node=nextTake[node];
	}
	cout<<'\n';


	return 0;
}