#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
using VI = vector<int>;

const int NN = 2e5+10;
char s[NN], t[NN];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  cin>>n;
  scanf("%s %s", s+1, t+1);
  VI v[2];
  for(int i=1; i<=n; i++) {
  	if(s[i] != t[i]) {
  		v[s[i]-'a'].pb(i);
  	}
  }
  if(((int)v[0].size() + (int)v[1].size())&1) return puts("-1"), 0;
  if(((int)v[0].size())&1) {
  	printf("%d\n", (v[0].size()+v[1].size()-2)/2+2);
  	for(int i=1; i<v[0].size(); i+=2) printf("%d %d\n", v[0][i], v[0][i+1]);
  	for(int i=1; i<v[1].size(); i+=2) printf("%d %d\n", v[1][i], v[1][i+1]);
  	cout<<v[0][0]<<' '<<v[0][0]<<endl;
  	cout<<v[0][0]<<' '<<v[1][0]<<endl;
  }else {
  	printf("%d\n", (v[0].size()+v[1].size())/2);
  	for(int i=0; i<v[0].size(); i+=2) printf("%d %d\n", v[0][i], v[0][i+1]);
  	for(int i=0; i<v[1].size(); i+=2) printf("%d %d\n", v[1][i], v[1][i+1]);
  }
  return 0;
}