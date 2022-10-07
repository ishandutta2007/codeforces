#include <map>
#include <iostream>
#include <string>

using namespace std;
int main ()
{map <string,int> vs;
int n,mif=0;
string s;
cin>>n;
for (int i=0; i<n; i++)
{mif=0;
cin>>s;
vs[s]++;
if (vs[s]>1) cout<<s<<vs[s]-1<<endl;
else cout<<"OK"<<endl;
}
//system ("pause");
return 0;
}