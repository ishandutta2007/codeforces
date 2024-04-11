# include <iostream>
# include <string>
using namespace std;
string s;
int main()
{
    bool p=0;
    cin>>s;
    if (s[0]=='-')
    {
        char max;
        if (s[s.length()-1]>s[s.length()-2])
            s[s.length()-1]=';';
        else
            s[s.length()-2]=';';
        
        if (s.length()==3 && (s[1]=='0' && s[2]==';') || (s[1]==';' && s[2]=='0'))
        {
            cout<<0<<endl;
            p=1;
        }


    }
    if (p==0)
    {
    for (int i=0;i<s.length();i++)
        if (s[i]!=';')
            cout<<s[i];
    cout<<endl;
    }
}