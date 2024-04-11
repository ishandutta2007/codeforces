#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main ()
{   vector <string> v;
    string s;
    int a,b=0,c;
    cin>>c;
    while (b<c)
    {cin>>s;
    v.push_back(s);
    b++;
}
b=0;
    while (b<c)
    {if (v[b].length()<=10) cout<<v[b]<<endl;
    else
    cout<<v[b][0]<<v[b].length()-2<<v[b][v[b].length()-1]<<endl;
    b++;}                           
return 0;
}