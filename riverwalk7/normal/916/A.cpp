#include <iostream>
#include <fstream>
using namespace std;
int x, h, m;
bool lucky()
{
    if(h%10==7)
    {
        return true;
    }
    if(m%10==7)
    {
        return true;
    }
    return false;
}
void subtract()
{
    m -= x;
    if(m<0)
    {
        h -= 1;
        m += 60;
    }
    if(h < 0)
    {
        h += 24;
    }
}
int main()
{
    cin>>x>>h>>m;
    int ans = 0;
    while(!lucky())
    {
        subtract();
        ++ans;
    }
    cout<<ans<<endl;
}