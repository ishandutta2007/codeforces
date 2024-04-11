#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int h, a, c, x, y;
vector<string> s;
int main()
{
    cin>>h>>a>>c>>x>>y;
    while(x > 0)
    {
        if(h > y||x<=a)
        {
            x -= a;
            h -= y;
            s.push_back("STRIKE");
        }
        else
        {
            h += (c-y);
            s.push_back("HEAL");
        }
    }
    cout<<s.size()<<endl;
    for(int i=0; i<s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
}