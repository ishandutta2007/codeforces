
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
    while(i<n)
    {
        if (s[i]=='.')
            cout<<0,i++;
        else
        {
            if (s[i+1]=='-')
                cout<<2;
            else
                cout<<1;
            i+=2;
        }
    }
    cout<<endl;
}