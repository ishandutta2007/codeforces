#include <iostream>
#include <fstream>
using namespace std;
bool between(int x, int y, int z)
{
    if(z <= y || y<=x)
    {
        return true;
    }
    return false;
}
int main()
{
    int h, m, s, t1, t2;
    cin>>h>>m>>s>>t1>>t2;
    h = 3600*h + 60*m + s;
    h %= 43200;
    m = 720*m+12*s;
    s = 720*s;
    t1 *= 3600;
    t2 *= 3600;
    t1 %= 43200;
    t2 %= 43200;
    if(t1 > t2)
    {
        swap(t1, t2);
    }
    if(t1 <= h && t2 >= h && t1<=m && t2>=m && t1<=s && t2>=s)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    else if(between(t1, h, t2) && between(t1, m, t2) && between(t1, s, t2))
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}