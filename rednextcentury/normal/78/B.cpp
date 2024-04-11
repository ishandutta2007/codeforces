
# include <iostream>
# include <string>
# include <cstdlib>
#define EPS 1e-9
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s="ROYGBIV";
    cout<<s;
    n-=7;
    s="GBIV";
    while(n>0)
    {
        cout<<s.substr(0,min(n,4));
        n-=min(n,4);
    }
    cout<<endl;
}