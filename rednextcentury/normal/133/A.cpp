# include <algorithm>
# include <iostream>
using namespace std;
int main ()
{
    string s;
    cin>>s;
    bool is=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='9' || s[i]=='H' || (s[i]=='Q'))
            is=1;
    }
    if (is)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}