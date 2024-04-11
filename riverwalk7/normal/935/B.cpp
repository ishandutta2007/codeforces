#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int N;
string s;
int a, b;
bool state;
int ans;
int main()
{
    cin>>N>>s;
    for(int i=0; i<N; i++)
    {
        if(s[i]=='R')
        {
            a++;
        }
        else
        {
            b++;
        }
        if(a>b)
        {
            if(!state&&i!=0)
            {
                ans++;
            }
            state = true;
        }
        if(a<b)
        {
            if(state)
            {
                ans++;
            }
            state = false;
        }
    }
    cout<<ans<<endl;
}