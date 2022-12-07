#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string s;
int main()
{
    cin>>s;
    int ans = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}