# include <iostream>
# include <string>
using namespace std;
int main ()
{
    string s;
    cin>>s;
    bool x=0;
    bool c=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]==tolower(s[i]) && i!=0)
            x=1;
        
        
    
    }
    
    if (x==1)
        cout<<s<<endl;
    else
    {
    for (int i=0;i<s.length();i++)
        {
            if (tolower(s[i])==s[i])
                cout<<char (toupper(s[i]));
            else
                cout<<char (tolower(s[i]));
        }
    
    cout<<endl;
    }
}