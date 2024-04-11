#include <bits/stdc++.h>
using namespace std;
int n,m;

const int INF = 1000100000;
vector<pair<int, int>> cannons[600];
void dijkstra(int s, vector<int> & d) {
    d.assign(n*n, INF);
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
	int t = d_v%n;
        q.pop();
        if (d_v != d[v])
            continue;
	// compute the cannons
	vector<int> edgetimes(n,INF);
	for(auto p: cannons[v]){
	  edgetimes[(t+p.first)%n] = p.second;
	}
	//roll around the edge times
	for(int i=1;i<n;++i){
	  edgetimes[i]=min(edgetimes[i],1+edgetimes[i-1]);
	}
	edgetimes[0]=min(edgetimes[0], 1+edgetimes[n-1]);
	for(int i=1;i<n;++i){
	  edgetimes[i]=min(edgetimes[i],1+edgetimes[i-1]);
	}
	for(int i=0;i<n;++i){
	  int to_time = (edgetimes[i]+t)%n;
	  int to = i;
	  int elen = edgetimes[i];
	  //cout<<"GOING TO "<<to<<" from "<<v<<endl;
	  if (d[v] + elen < d[to]) {
	    d[to] = d[v] + elen;
	    q.push({d[to], to});
	  }
        }
    }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>m;
  // i + n*t
  for(int i=0;i<m;++i){
    int a,b,c;
    cin>>a>>b>>c;
    cannons[a].emplace_back(b,c);
  }
  for(int i=0;i<n;++i){
    vector<int> d(n);
    dijkstra(i,d);
    for(int j=0;j<n;++j){
      for(int t=1;t<n;++t){
	d[j] = min(d[j],d[j+t*n]);
      }
    }
    cout<<d[0];
    for(int j=1;j<n;++j){
      cout<<" "<<d[j];
    }
    cout<<'\n';
  }
  cout<<flush;
}