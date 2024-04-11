
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int i=0;
    while(s[i]!='.') i++;
    if (s[i+1]>='5')
    {
        if (s[i-1]=='9')
            cout<<"GOTO Vasilisa."<<endl;
        else
            cout<<s.substr(0,i-1)<<char((int)s[i-1]+1)<<endl;
    }
    else if (s[i-1]!='9')
        cout<<s.substr(0,i)<<endl;
    else
        cout<<"GOTO Vasilisa."<<endl;
}