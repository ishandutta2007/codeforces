#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1000000007;
int xa[101];
int ya[101];
int xb[101];
int yb[101];
int tn[101];
int n,m;
int tds[14][1<<14];
int qds [100][1<<14];
int nds[100][14];
int qqds[100][100];

int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n>>m;
  // game state is num quests completed, position, activated towers, time
  // can activate more than one tower during a time-wait
  // only positions to worry about are towers and goals before they are claimed
  
  // 2^n * (n+m) states (1.6 mil) + 2^n * m tower,numtasks combos
  // only propagate max from each tower once
  // propagate 
  // each state, next move is to a tower or a goal
  // time at a goal is certain, but increase the value by calculating max number of goals

  // position is 2^m * towerpos + bitset
  for(int i=0;i<n;++i){
    cin>>xa[i]>>ya[i];
  }
  std::vector<pair<int,pair<int,int>>> ts(m);
  for(int i=0;i<m;++i){
    cin>>ts[i].second.first>>ts[i].second.second>>ts[i].first;
  }
  sort(ts.begin(),ts.end());
  for(int i=0;i<m;++i){
    xb[i]=ts[i].second.first;
    yb[i]=ts[i].second.second;
    tn[i]=ts[i].first;
  }
  // nodes 0-(2^n *m -1) are tower-set, number quest combos (at tower)
  // nodes 2^n *m - 2^n *m + 2^n *m -1 are tower-set, quest position

  int nnodes = (2<<n)*m;
  //cout<<nnodes<<endl;
  for(int i=0;i<n;++i){
    tds[i][0]=INF;
    for(int j=0;j<n;++j){
      tds[i][1<<j] = abs(xa[i]-xa[j])+abs(ya[i]-ya[j]);
    }
    for(int j=1;j<(1<<n);++j){
      int lsb = j & (-j);
      tds[i][j] = min(tds[i][j-lsb],tds[i][lsb]);
    }
  }
  for(int i=0;i<m;++i){
    //    tds[0]=0;
    qds[i][0] = INF;
    for(int j=0;j<n;++j){
      nds[i][j]    = abs(xb[i]-xa[j])+abs(yb[i]-ya[j]);
      qds[i][1<<j] = abs(xb[i]-xa[j])+abs(yb[i]-ya[j]);
    }
    for(int j=0;j<m;++j){
      qqds[i][j] = abs(xb[i]-xb[j])+abs(yb[i]-yb[j]);
    }
    for(int j=1;j<(1<<n);++j){
      int lsb = j & (-j);
      qds[i][j] = ( min(qds[i][j-lsb],qds[i][lsb]));
    }
  }

  vector<int> d(nnodes,INF);
  // add all the basic starting points
  vector<int> mnq(nnodes,0);
  for(int i=0;i<m;++i){
    int sv=(m+i)<<n;
    mnq[sv]=1;
    d[sv]=tn[i];
    // q.emplace(d[sv],sv);
  }
  for(int i=0;i<n;++i){
    mnq[1<<i]=0;
    d[1<<i] = 0;
    //q.emplace(0,1<<i);
  }
  int tbm = (1<<n)-1;  
  for(int mask=0;mask<=tbm;++mask){
    for(int QN=0;QN<2*m;++QN){
      int v = mask + (QN<<n);
      int d_v = d[v];
      if( d[v] == INF)continue;
      
      if( v>=nnodes/2){
     
      int qng= v- (nnodes/2);
      int qn = qng>>n;
      int bm = qng&tbm;
      if(d_v > tn[qn])continue;
      // we're at a quest
      // if we're past quest time, die.
      // go to tower
      //cout<< "Reach quest "<<qn<<" in "<<d[v]<<" time totalling "<<mnq[v]<<" quests with "<<bm<< "tower bitmap unlocked"<<endl;
      
      for(int t=0;t<n;++t){
	//already seeing this tower
	if( (bm>>t)&1) continue;
	int tobm=bm|(1<<t);
	int time = tn[qn]+min(tds[t][bm],nds[qn][t]);
	int nq = mnq[v];
	if(nq == m){
	  //can hit all quests, don't care.
	  cout<<m<<endl;
	  exit(0);
	}
	int tv= tobm + (nq<<n);
	if( time<d[tv]){
	  d[tv] = time;
	  //q.emplace(d[tv],tv);
	 
	}
      }
      // go to quest
      for(int Q=0;Q<m;++Q){
	if(Q ==qn) continue;
	int time = tn[qn]+min(qds[Q][bm],qqds[qn][Q]);
	int tv = bm + ((Q+m)<<n);
	if(time >tn[Q]) continue;
	if(d[tv]>tn[Q]){
	  d[tv] = tn[Q];
	  //q.emplace(d[tv],tv);
	}
	mnq[tv] = max(mnq[tv],1+mnq[v]);
      }
    }else{
      
      // we just finished a tower, 
      int nc = v >> n;
      int bm = v & tbm;
      //cout<<"Reach towerset "<<bm<<" with "<<nc<<" quests in time"<<d[v]<<endl;
      for(int t=0;t<n;++t){
	//already seeing this tower
	if( (bm>>t)&1) continue;
	int tobm=bm|(1<<t);
	int time = d_v + tds[t][bm];
	int tv= tobm + (nc<<n);
	if( time<d[tv]){
	  d[tv] = time;
	  
	  //q.emplace(d[tv],tv);
	}
      }
      // go to quest
      for(int Q=0;Q<m;++Q){
	int time = d_v + qds[Q][bm];
	int tv = bm + ((Q+m)<<n);
	if(time > tn[Q]) continue;
	if(d[tv]>tn[Q]){
	  d[tv] = tn[Q];
	  //  q.emplace(d[tv],tv);
	}
	mnq[tv] = max(mnq[tv],1+nc);
	
      }
    }
    }
  }
  int res = *(max_element(mnq.begin(),mnq.end()));
  cout<<res<<endl;
}