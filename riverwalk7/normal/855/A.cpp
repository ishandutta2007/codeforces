#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, bool> m;
string x; int N;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        if(m[x])
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            m[x] = true;
        }
    }
}