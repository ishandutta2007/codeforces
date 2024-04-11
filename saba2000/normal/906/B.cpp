#include<bits/stdc++.h>
using namespace std;
int f[509],g[509];
vector<int> a[100009];
main()
{
  int n,m;
  cin>>n>>m;

  if(n==1 && m==1 )
  {
      cout<<"YES"<<endl<<1<<endl;
      return 0;
  }
  if(n+m<=4 || n==2 && m==3 ||  n==3 && m==2)
  {
      cout<<"NO"<<endl;
      return 0;
  }
  cout<<"YES"<<endl;
  if(n==1 && m==4)
  {
      cout<<"3 1 4 2"<<endl;
  }
  if(n==4 && m==1)
  {
      cout<<3<<endl<<1<<endl<<4<<endl<<2<<endl;
  }
  if(n==2 && m==4)
  {
      cout <<"5 4 7 2"<<endl<<"3 6 1 8 "<<endl;
  }
  if(n==4 && m==2)
  {
      cout<<"2 5"<<endl<<"7 4"<<endl<<"6 1"<<endl<<"3 8"<<endl;
  }
  if(n==3 && m==3)
  {

      cout<<"5 1 9\n3 7 2\n4 6 8\n";

  }
  if(n==3 && m==4)
  {
   cout<<"3 1 4 2\n6 8 5 7\n11 9 12 10\n";
  }
  if(n==4 && m==3)
  {

   cout<<"7 5 9\n1 11 3\n10 2 12\n4 8 6\n";
  }
  if(n==4 && m==4)
  {
   cout<<"3 1 4 2\n6 8 5 7\n11 9 12 10\n14 16 13 15\n";
  }
  if(n<5 && m<5) return 0;
  int fl=0;

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
        a[i].push_back(0);
  if(n>=5 && m<5) {swap(m,n); fl=1;}
  for (int i=0; i<n; i++)
  {
      int x=i%2,y=1-i%2;
      int t=0;
      for (int j=x; j<m; j+=2)
       if(fl)a[t++][i]=j*n+i+1;
       else a[i][t++]=i*m+j+1;
      for (int j=y; j<m; j+=2)
        if(fl)a[t++][i]=j*n+i+1;
       else a[i][t++]=i*m+j+1;
  }
  if(fl) swap(m,n);

      for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
      {
        cout<<a[i][j]<<" ";
      }
      cout<<endl;}

}