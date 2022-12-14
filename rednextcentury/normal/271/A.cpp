# include <algorithm>
# include <iostream>
using namespace std;

bool check(int y)
{
    int v[11]={0};
    while(y!=0)
    {
        if (++v[y%10]>1)
            return 0;
        y/=10;
    }
    return 1;
}

int main ()
{
    int y;
    cin>>y;
    y++;
    while(1)
    {
        if (check(y))
        {
            cout<<y<<endl;
            return 0;
        }
        y++;
    }
}