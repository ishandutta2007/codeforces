#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC;
  cin>>TC;
  while(TC-->0){
    int n;
    cin>>n;
    vector<int> stack;
    for(int i=0;i<n;++i){
      int t;
      cin>>t;
      if(t==1){
	stack.push_back(1);	
      }else{
	while(stack.back()!=t-1){
	  stack.pop_back();
	}
	++stack[stack.size()-1];
      }
      for(int j=0;j<stack.size();++j){
	cout<<stack[j]<<((j==stack.size()-1)?"\n":".");
      }
    }
  }
  cout<<flush;
}