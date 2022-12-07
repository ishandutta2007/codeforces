#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string s;
int counter;
string t;
int main()
{
    cin>>s;
    t = "heidi";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == t[counter])
        {
            counter++;
        }
        if(counter==5)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}