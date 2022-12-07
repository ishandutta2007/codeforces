#include <iostream>
#include <fstream>
using namespace std;
string s[5]; string t;
int main()
{
    cin>>t;
    for(int i=0; i<5; i++)
    {
        cin>>s[i];
        if(s[i][0]==t[0]||s[i][1]==t[1])
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}