#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int maxn=200001;

struct Node {
  vector<Node*> adj;
  vector<int> edgeCosts;
  int zeroSubtree;
  int oneOnlySubtree;
  int oneReachableSubtree;

  void precomp(Node* par) {
    for (int i=0; i<adj.size(); i++) {
      if (adj[i]==par) {
        adj.erase(adj.begin()+i);
        edgeCosts.erase(edgeCosts.begin()+i);
      }
    }
    zeroSubtree=oneReachableSubtree=oneOnlySubtree=1;
    for (int i=0; i<adj.size(); i++) {
      adj[i]->precomp(this);
      if (!edgeCosts[i]) {
        zeroSubtree+=adj[i]->zeroSubtree;
        oneReachableSubtree+=adj[i]->oneReachableSubtree;
      }
      else {
        oneOnlySubtree+=adj[i]->oneOnlySubtree;
        oneReachableSubtree+=adj[i]->oneOnlySubtree;
      }
    }
    //printf("Done with precomp, zeroSubtree: %d, oneOnlySubtree: %d, oneReachableSubtree%d\n",
    //    zeroSubtree, oneOnlySubtree, oneReachableSubtree);
  }

  ll getTotalPairs(int zeroAbove, int oneOnlyAbove, int oneReachableAbove) {
    //printf("Getting total pairs, zeroAbove:%d, oneOnlyAbove%d, oneReachableAbove%d\n", zeroAbove, oneOnlyAbove,
    //    oneReachableAbove);
    ll total=0;
    //total+=max(0, zeroAbove+zeroSubtree-1);
    total+=max(0, oneReachableSubtree+oneReachableAbove-1);
    //printf("Added %lld\n", total);
    for (int i=0; i<adj.size(); i++) {
      if (!edgeCosts[i]) {
        int newZeroAbove=zeroAbove+zeroSubtree-adj[i]->zeroSubtree;
        int newOneOnlyAbove=0;
        int newOneReachableAbove=oneReachableAbove+oneReachableSubtree-adj[i]->oneReachableSubtree;
        total+=adj[i]->getTotalPairs(newZeroAbove, newOneOnlyAbove, newOneReachableAbove);
      }
      else {
        int newZeroAbove=0;
        int newOneOnlyAbove=oneOnlyAbove+oneOnlySubtree-adj[i]->oneOnlySubtree;
        int newReachableAbove=newOneOnlyAbove;
        total+=adj[i]->getTotalPairs(newZeroAbove, newOneOnlyAbove, newReachableAbove);
      }
    }
    return total;
  }
};

Node nodes[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin>>n;
  for (int i=1; i<n; i++) {
    int a, b, c;
    cin>>a>>b>>c;
    a--;
    b--;
    nodes[a].adj.push_back(&nodes[b]);
    nodes[b].adj.push_back(&nodes[a]);
    nodes[a].edgeCosts.push_back(c);
    nodes[b].edgeCosts.push_back(c);
  }
  nodes[0].precomp(NULL);
  ll ans=nodes[0].getTotalPairs(0, 0, 0);
  //ans/=2;
  cout<<ans<<endl;

  return 0;
}