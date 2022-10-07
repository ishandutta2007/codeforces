#include <iostream>
using namespace std;
int main ()
{
    int p[10][10],n;
    cin>>n;
    for (int i=0; i<10; i++)
   { p[0][i]=1; p[i][0]=1; }
   for (int i=1; i<10; i++)
   {
   for (int j=1; j<10; j++)
   {
   p[i][j]=p[i-1][j]+p[i][j-1];
 
}
cout<<endl;
}
cout<<p[n-1][n-1]<<endl;
//system ("pause");
return 0;
}