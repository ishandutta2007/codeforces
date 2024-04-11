#include <iostream>
#include <deque>
#include <vector>
#include <utility>

#define maxn 200001

using namespace std;

typedef pair<int, int> ii;

vector<int> adj[maxn];
int main() {
  int n, m, black[maxn]={0}, visited[maxn]={0};
  cin>>n>>m;
  vector<ii*> edges;
  
  for (int i=0; i<m; i++) {
    int a, b;
    cin>>a>>b;
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edges.push_back(new ii(a, b));
  }
  
  deque<int> queue;
  visited[0]=1;
  queue.push_back(0);
  int works=1;
  
  while (!queue.empty()) {
    int next=queue.front();
    queue.pop_front();
    for (int nn:adj[next]) {
      if (visited[nn]&&black[nn]==black[next])
        works=0;
      if (visited[nn])
        continue;
      black[nn]=!black[next];
      queue.push_back(nn);
      visited[nn]=true;
    }
  }
  if (!works) {
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  for (ii* e:edges) {
    cout<<(black[e->first]!=0);
  }
  cout<<'\n';
  return 0;
}