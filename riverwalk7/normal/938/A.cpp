#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int N; string s;
bool v[101];
int main()
{
    cin>>N>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
        {
            v[i] = true;
        }
        if(i==0||!(v[i]&&v[i-1]))
        {
            cout<<s[i];
        }
    }
    cout<<""<<endl;
}