# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if (s.length()<5)
    {
        cout<<"Too weak\n";
    }
    else
    {
        bool upper=0;
        bool lower=0;
        bool dig=0;
        for (int i=0;i<s.length();i++)
        {
            if (s[i]>='0' && s[i]<='9')
            dig=1;
            if (s[i]>='a' && s[i]<='z')
            lower=1;
            if (s[i]>='A' && s[i]<='Z')
            upper=1;
        }
        if (upper==1 && lower==1 && dig==1)
        cout<<"Correct\n";
        else
        cout<<"Too weak\n";
    }
}