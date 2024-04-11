#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
struct blocktree{
  int d=0;
  bool split=false;
  bool claimed=false;
  int blockno=-1;
  vector<blocktree> desc;
  blocktree(int dep): d(dep){
  }
};
struct block{
  int d;
  ll trace;
  bool active = false;
  block(int dep, ll tr): d(dep),trace(tr){}
  vector<int> futures;
};
void addfree(blocktree& bt, vector<block>& blocks,ll trace,int d){
  if(bt.claimed)return;
  if(!bt.split){
    bt.blockno = blocks.size();
    blocks.emplace_back(d,trace);
    return;
  }
  addfree(bt.desc[0],blocks,trace,d+1);
  addfree(bt.desc[1],blocks,trace+(1ll<<d),d+1);
}
void insert(blocktree& bt,ll l,ll r, int N,vector<block>& blocks,ll trace, int d){
  //cout<<l<<" "<<r<<" "<<N<<endl;
  if(bt.claimed)return;
  if(!bt.split){
    if(l==0&& r==(1ll<<N)-1){
      //don't need to split, just fill
      bt.claimed=true;
      bt.blockno=blocks.size();
      blocks.emplace_back(d,trace);
      return;
    }
    else{
      // split
      bt.split = true;
      bt.desc.push_back( blocktree(bt.d+1));
      bt.desc.push_back( blocktree(bt.d+1));
    }
  }
  ll spl = (1ll<<(N-1));
  if(l<spl){
    insert(bt.desc[0],l,min(r,spl-1),N-1,blocks,trace,d+1);
  }
  if(r>=spl){
    insert(bt.desc[1],max(l-spl,0ll),r-spl,N-1,blocks,trace+(1ll<<d),d+1);
    // have to do right
  }
  bt.claimed = bt.desc[0].claimed && bt.desc[1].claimed;
}

struct dsu{
  vector<int> parent, rank;
  int n;
  dsu(int N): parent(N,0), rank(N,0),n(N){
    for(int i=0;i<N;++i)make_set(i);
  }
  void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
  }
  
  int find_set(int v) {
    //assert(v>=0&&v<n);
    if (v == parent[v])
      return v;
    return parent[v] = find_set(parent[v]);
  }
  
  bool join(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (rank[a] < rank[b])
            swap(a, b);
      parent[b] = a;
      if (rank[a] == rank[b])
        rank[a]++;
      return true;
    }
    return false;
  }
};
int find_block(blocktree& bt, ll v,int N){
  if(!bt.split)return bt.blockno;
  ll spl = (1ll<<(N-1));
  if(v>=spl)
    return find_block(bt.desc[1],v-spl,N-1);
  return find_block(bt.desc[0],v,N-1);
}
void proc_block(dsu* d, vector<block>& blocks, int id, blocktree& bt){
  const block& b = blocks[id];
  blocks[id].active = true;
  for(const int& k : b.futures)d->join(k,id);

  blocktree* urr= &bt;
  for(int i=0;i<b.d;++i){
    ll pr = b.trace ^(1ll<<i);
    blocktree* curr = urr;
    for(int j=i;j<b.d;++j){
      if(curr->blockno>=0){
        break;
      }
      else{
        // assert(curr->split);
        curr = & (curr->desc[1&(pr>>j)]);
      }
    }
    int bn = curr->blockno;
    if(bn>=0){
      if(blocks[bn].active)
        d->join(bn,id);
      else blocks[bn].futures.push_back(id);
    }
    urr = &(urr->desc[1&(b.trace>>i)]);
  }
  // go down the blocktree and try deleting 
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  int N,M;
  cin>>N>>M;
  vector<pair<bool,pair<ll,ll>>> qs(M);
  vector<vector<int>> blocklists(M);
  vector<block> blocks;
  blocktree bt(0);
  for(int i=0;i<M;++i){
    string k;
    cin>>k;
    qs[i].first = (k=="ask");
    cin>>qs[i].second.first>>qs[i].second.second;
    int nb = blocks.size();
    if(!qs[i].first){
      insert(bt,qs[i].second.first,qs[i].second.second,N,blocks,0,0);
      int nq = blocks.size();
      for(int j=nb;j<nq;++j)blocklists[i].push_back(j);
    }
  }
  // reverse-process a dsu
  // split into trie where you don't manifest if all below are in same state (on/off)
  // if entire node in trie is active, can go to any node descendant of any complement
  // say node i is 'connected', then any descendant that is active should also be connected?
  // node i at level j where fully free below

  
  // create free nodes in the tree
  int nb = blocks.size();
  addfree(bt,blocks,0,0);
  // add dsu
  dsu d(blocks.size());
  
  
  for(int j=nb;j<blocks.size();++j){
    proc_block(&d,blocks,j,bt);
  }
  vector<bool> answers;
  for(int k=M-1;k>=0;--k){
    if(qs[k].first){
      ll a = qs[k].second.first;
      ll b = qs[k].second.second; 
      int ab = find_block(bt,a,N);
      int bb = find_block(bt,b,N);
      //cout<<a<<" "<<ab<<" "<<b<<" "<<bb<<endl;
      answers.push_back(d.find_set(ab)==d.find_set(bb));
    }else{
      for(int x:blocklists[k])proc_block(&d,blocks,x,bt);
    }
  }
  for(int j=answers.size()-1;j>=0;--j)cout<<(answers[j]?1:0)<<'\n';
  cout<<flush;
}