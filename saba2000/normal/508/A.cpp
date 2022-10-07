#include <iostream>
using namespace std;
int main ()
{
    int a[1001][1001];
    int n,m,k,i,j,t=0,r=-1;
    cin>>n>>m>>k;
    for (int p=0; p<k; p++)
    {
    cin>>i>>j; i=i-1; j=j-1; a[i][j]=1;
    
    if (t==0)
    {
    if (a[i][j]==a[i+1][j] && a[i][j]==a[i][j+1] && a[i][j]==a[i+1][j+1]) { t=1; r=p;}
    if (a[i][j]==a[i-1][j] && a[i][j]==a[i][j-1] && a[i][j]==a[i-1][j-1]) { t=1; r=p;}
    if (a[i][j]==a[i+1][j] && a[i][j]==a[i][j-1] && a[i][j]==a[i+1][j-1]) { t=1; r=p;}
    if (a[i][j]==a[i-1][j] && a[i][j]==a[i][j+1] && a[i][j]==a[i-1][j+1]) { t=1; r=p;}
}
}
cout<<r+1<<endl; 

return 0;
}