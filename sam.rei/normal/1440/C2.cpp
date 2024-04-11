#include "bits/stdc++.h"

using namespace std;
//static int w[100000];
//static char s[300001];
#define ll long long 
static ll a[200001], b[200001];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ct;
  cin >>ct;
  while(ct-->0){
    int n,m;
    cin>>n>>m;
    string s;
    getline(cin,s);
    vector<vector<bool>> rows(n,vector<bool>());
    for(int i=0;i<n;++i){
      getline(cin,s);
      for(char c : s) rows[i].push_back(c=='1');
    }
    vector<vector<int>> tuples;
    for(int i=n-1;i>=2;--i){
      for(int j=0;j<m;++j){
	if(rows[i][j]){
	  vector<int> flip{i,j,i-1,j,i-1};
	  rows[i][j]=!rows[i][j];
	  rows[i-1][j]=!rows[i-1][j];
	  if(j<m-1){
	    flip.push_back(j+1);
	  }
	  else flip.push_back(j-1);
	  rows[i-1][flip[5]] =!rows[i-1][flip[5]];;
	  tuples.push_back(flip);
	}
      }
    }
    for(int i=m-1;i>=2;--i){
      for(int j=0;j<2;++j){
	if(rows[j][i]){
	  vector<int> flip{j,i,0,i-1,1,i-1};
	  rows[j][i]=!rows[j][i];
	  rows[0][i-1]=!rows[0][i-1];
	  rows[1][i-1]=!rows[1][i-1];
	  tuples.push_back(flip);
	}
      }
    }
    int c = 0;
    
    if(rows[0][0]){
      c+=1;
    }
    if(rows[0][1]){
      c+=2;
    }
    if(rows[1][0]){
      c+=4;
    }
    if(rows[1][1]){
      c+=8;
    }

    switch(c){
    case 0:
      break;
    case 1:{
      vector<vector<int>> x1{{0,0,0,1,1,1},{0,0,1,0,1,1},{0,0,0,1,1,0}};
      tuples.insert(tuples.end(),x1.begin(),x1.end());
      break;
    }
    case 2:{
	   vector<vector<int>> x2{{0,0,0,1,1,1},{0,1,1,0,1,1},{0,0,0,1,1,0}};
      tuples.insert(tuples.end(),x2.begin(),x2.end());break;
    }case 4:{
       vector<vector<int>> x4{{1,0,0,1,1,1},{0,0,1,0,1,1},{0,0,0,1,1,0}};
      tuples.insert(tuples.end(),x4.begin(),x4.end());break;
    }case 8:{
       vector<vector<int>> x8{{0,0,0,1,1,1},{0,0,1,0,1,1},{1,1,0,1,1,0}};
      tuples.insert(tuples.end(),x8.begin(),x8.end());break;
    }case 7:{
      vector<int> x7{0,0,1,0,0,1};
      tuples.push_back(x7);break;
    }case 11:{
      vector<int> x11{0,0,0,1,1,1};
      tuples.push_back(x11);break;
    }case 13:{
      vector<int> x13{1,0,0,0,1,1};
      tuples.push_back(x13);break;
    }case 14:{
      vector<int> x14{1,0,0,1,1,1};
      tuples.push_back(x14);break;
    }case 15:{
      vector<vector<int>> x15{{0,0,1,0,0,1},
			      {0,0,0,1,1,1},{0,0,1,0,1,1},{1,1,0,1,1,0}};
      tuples.insert(tuples.end(),x15.begin(),x15.end());break;
    }
    default:
      for(int i=0;i<4;++i){

	if(rows[i/2][i%2]){
	  vector<int> x{i/2,i%2};
	  for(int j=0;j<4;++j){
	    if(!rows[j/2][j%2]){
	      x.push_back(j/2);
	      x.push_back(j%2);
	    }
	  }
	  tuples.push_back(x);
	}
		       
      }
      
    }
    // const vector<int> o{1,0,3,2,5,4};
    cout<<tuples.size()<<'\n';
    for(auto x : tuples){
      for(int i=0;i<6;++i){
	cout<<x[i]+1<<(i==5?'\n':' ');;
      }
    }
  }

  cout<<flush;
  return 0;
}