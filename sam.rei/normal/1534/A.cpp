#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()
void one(){
  int n,m;
  cin>>n>>m;
  vector<string> v(n);
  for(int i=0;i<n;++i)cin>>v[i];
  int setting = -1;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      int newsetting;
      switch(v[i][j]){
      case 'R':
	newsetting= (i+j)%2;
	if(setting==-1)setting=newsetting;
	else if (setting!=newsetting){
	  cout<<"NO\n";
	  return;
	}
	break;
      case 'W':
	newsetting= (i+j+1)%2;
	if(setting==-1)setting=newsetting;
	else if (setting!=newsetting){
	  cout<<"NO\n";
	  return;
	}
	break;
      default:
	break;
      }
    }
  }
  if(setting==-1){
    setting=0;
  }
  cout<<"YES\n";
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      v[i][j]= (setting + i+j)%2 == 0?'R':'W';
    }
    cout<<v[i]<<"\n";
  }

}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}