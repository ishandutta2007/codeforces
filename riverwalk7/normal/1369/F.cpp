#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
typedef long long ll;
ll s[MAXN], e[MAXN];
int T;
bool f(ll a, ll b, bool c)
{
    if(!c)
    {
        if(a > b/2)
        {
            return true;
        }
        else
        {
            b = b/2;
        }
    }
    while(true)
    {
        if(b%2)
        {
            return (1-a)%2;
        }
        else
        {
            if(a > b/2)
            {
                return a%2;
            }
            else
            {
                b = b/2;
                if(a > b/2)
                {
                    return true;
                }
                b = b/2;
            }
        }
    }
}
bool solve(bool goal)
{
    for(int i=T-1; i>=0; i--)
    {
        goal = !f(s[i], e[i], goal);
    }
    return !goal;
}
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>s[i]>>e[i];
    }
    cout<<solve(true)<<" "<<solve(false)<<endl;
}