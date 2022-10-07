#include <iostream>
using namespace std;
int main ()
{
    int n,m,k[50][50];
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
    for (int j=0; j<m; j++)
    {
    if (i%2==0) cout<<"#";
    else
    if (i%4==1 && j==m-1) cout<<"#";
    else 
    if (i%4==3 && j==0) cout<<"#";
    else cout<<".";
}
cout<<endl;
}
//system ("pause");
return 0;
}