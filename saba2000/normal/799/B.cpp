#include<bits/stdc++.h>
using namespace std;
vector <int> v[5][5];
int X[200009],Y[200009],Z[200009];
int c[5][5];
int main()
{int n;
cin>>n;
for (int i=0; i<n; i++)
cin>>X[i];
for (int i=0; i<n; i++)
cin>>Y[i];
for (int i=0; i<n; i++)
{cin>>Z[i];
v[Y[i]][Z[i]].push_back(X[i]);}
for (int i=1; i<=3; i++)
for (int j=1; j<=3; j++)
sort(v[i][j].begin(),v[i][j].end());
int m;
cin>>m;
for(int i=0; i<m; i++)
{int C,x=-1,y,ans=0;
cin>>C;
for(int i=1; i<=3; i++)
for (int j=1; j<=3; j++)
if((i==C || j==C) && c[i][j]<v[i][j].size() && (x==-1 || ans>v[i][j][c[i][j]]) ){x=i; y=j; ans=v[i][j][c[i][j]];}
if(x==-1) {cout<<-1<<" "; continue;}
cout<<ans<<" ";
c[x][y]++;
}

}