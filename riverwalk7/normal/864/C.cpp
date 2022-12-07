#include <iostream>
#include <vector>
using namespace std;
int a, b, f, k;
vector<int> d;
int x, ans;
int main()
{
    cin>>a>>b>>f>>k;
    for(int i=0; i<=k; i++)
    {
        if(i==0||i==k)
        {
            d.push_back(f);
        }
        else
        {
            d.push_back(2*f);
        }
        f = a-f;
    }
    x = b;
    for(int i=0; i<d.size(); i++)
    {
        if(d[i] > b)
        {
            cout<<-1<<endl;
            return 0;
        }
        else if(x >= d[i])
        {
            x -= d[i];
        }
        else
        {
            ++ans;
            x = b - d[i];
        }
    }
    cout<<ans<<endl;
}