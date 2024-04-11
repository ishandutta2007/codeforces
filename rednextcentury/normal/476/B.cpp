# include <bits/stdc++.h>
using namespace std;
long double tot=1;
int loc;
    string a,b;
int ans;
int n;
void solve(int i,int l)
{
  if (i==n)
    ans+=(l==loc);
  else
  {
    if (b[i]=='+')solve(i+1,l+1);
    else if (b[i]=='-')solve(i+1,l-1);
    else solve(i+1,l+1),solve(i+1,l-1);
  }
}
int main()
{
  cin>>a>>b;
  int num=0;
   n=a.size();
  for (int i=0;i<n;i++){
    if (b[i]=='?')num++;
    if (a[i]=='+')loc++;
    else loc--;
  }
  tot=(1<<num);
  solve(0,0);
  cout<<setprecision(12)<<fixed<<ans/tot<<endl;
}