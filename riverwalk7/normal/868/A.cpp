#include <iostream>
#include <string>
using namespace std;
string s;
string t;
bool a, b;
int main()
{
    cin>>s;
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>t;
        if(t==s)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        if(t[0]==s[1])
        {
            a = true;
        }
        if(t[1]==s[0])
        {
            b = true;
        }
    }
    if(a && b)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}