#include <iostream>
using namespace std;
int main ()
{int n,d,s=0;
cin>>n>>d;
for (int i=0; i<n; i++)
{int t; cin>>t; s+=t;}
if (s>d-(n-1)*10) cout<<-1<<endl;
else cout<<(d-s)/5<<endl;
    return 0;
    
}