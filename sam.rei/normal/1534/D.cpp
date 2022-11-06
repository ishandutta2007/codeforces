#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
int n;
vector<int> p(2001,-1);
// first with distance 2
vector<int> pp(2001,-1);
vector<vector<int>> d(2001,vector<int>(2001,2001));
// check at distance 2, value that stays at 1 is between them, values that stay at 2 are connected to
//ignore those with distance >=3

void query(int q){
  //already queried
  if(d[q][q]!=0){
    cout<<"? "<<q<<endl;
    for(int i=1;i<=n;++i){
      cin>>d[q][i];
      if(d[q][i]==1){
	if(p[i]==-1){
	  p[i] = q;
	  pp[i]=p[q];
	}
	else{
	  p[q]=i;
	  pp[q]=p[i];
	}
      }
    }
  }
  for(int i=1;i<=n;++i){
    if(d[q][i]==2){
      if(pp[i]==-1){
	//first time we've seen
	pp[i]=q;
      }
      else{
	// another node at distance two from this,
	// share common ancestor, must share parent
	if(pp[i]==pp[q]){
	  p[i]=p[q];
	}
	else{
	  assert(i==pp[q]);
	}
      }
    }
  }
  if(q!=1){
    // fill in answers of the parent
    for(int i=1;i<=n;++i){
      if(d[q][i]==d[pp[q]][i]){
	d[p[q]][i]=d[q][i]-1;
      }
      else{
	d[p[q]][i] = 1+min(d[q][i],d[pp[q]][i]);
      }
      if(d[p[q]][i]==2&& pp[i]==-1){
	pp[i]=p[q];
      }
    }
  }
  
  
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  p[1]=0;
  pp[1]=0;
  query(1);
  bool found=true;
  while(found){
    found = false;
    for(int i=1;i<=n;++i){
      if(pp[i]!=-1 && p[i]==-1){
	query(i);
	found=true;
      }
    }
  }
  //
  
  
  cout<<"!\n";
  for(int i=2;i<=n;++i){
    cout<<i<<" "<<p[i]<<"\n";
  }
  cout<<flush;
}