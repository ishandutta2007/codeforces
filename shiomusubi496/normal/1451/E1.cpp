#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n;
  cin>>n;
  int a,b,c,d,e;
  puts("AND 2 3");fflush(stdout);
  cin>>a;
  puts("AND 1 3");fflush(stdout);
  cin>>b;
  puts("AND 1 2");fflush(stdout);
  cin>>c;
  puts("OR 1 2");fflush(stdout);
  cin>>d;
  puts("XOR 1 3");fflush(stdout);
  cin>>e;
  vector<int> ans(n);
  ans[0]=(((((a|b)&(~e))|((~(a|b))&e))|c)&d),ans[1]=(((~ans[0])&((~c)&d))|c),ans[2]=(e^ans[0]);
  for(int i=3;i<n;i++){
    cout<<"XOR 1 "<<i+1<<endl;fflush(stdout);
    int a;cin>>a;
    ans[i]=(ans[0]^a);
  }
  cout<<"!";
  for(int i=0;i<n;i++)cout<<' '<<ans[i];cout<<endl;fflush(stdout);
}