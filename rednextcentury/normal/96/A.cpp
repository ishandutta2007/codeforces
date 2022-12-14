
# include <iostream>
# include <string>
# include <map>
#define EPS 1e-9
using namespace std;
map<string,int> mp;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int now=1;
    for (int i=1;i<n;i++)
    {
        if (s[i]==s[i-1])
            now++;
        else
            now=1;
        if (now>=7)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}