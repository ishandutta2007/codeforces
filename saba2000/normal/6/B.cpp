#include <iostream>
using namespace std;
int main ()
{int n,m,u[300]={0},an=0; char p,l[109][109];
cin>>n>>m>>p; u['.']=1; u[p]=1;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
cin>>l[i][j];
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
if(u[l[i][j]]==0 && (l[i-1][j]==p || l[i+1][j]==p || l[i][j+1]==p || l[i][j-1]==p)) {an++;u[l[i][j]]=1;}
cout<<an<<endl;
return 0;
}