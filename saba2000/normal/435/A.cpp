#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector <int> a;
    int i=0,n,m,x=0,k=0;
    cin>>n>>m;
    while (i<n)
{cin>>k;
a.push_back(k);
i++;
}
k=0;
i=0;
    while (i<n)
    {
          if (x+a[i]<=m) {
          
          x+=a[i];
 i++;
          }
          else {
          x=0;
          k++;
        
        
          }
          }
    cout<<k+1<<endl;

    return 0;
     }