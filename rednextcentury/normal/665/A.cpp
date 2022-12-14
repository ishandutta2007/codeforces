#include<bits/stdc++.h>
using namespace std;
bool a[1000000];
int main()
{
    int l;
    cin>>l>>l;
    int f,e;
    cin>>f>>e;
    int h,m;
    char x;
    cin>>h>>x>>m;
    int st=5*60;
    int en=23*60+59;
    for (int i=st;i<=en;i+=f)
      a[i]=1;
      int ans=0;
    for (int i=h*60+m-e+1;i<h*60+m+l;i++)
     ans+=a[i];
     cout<<ans<<endl;
}