#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;
ll X, D, counter;
vector<ll> v;
int main()
{
    cin>>X>>D;
    counter = 1;
    while (X != 0)
    {
        counter += (D+100);
        ll z = 1; int y = 1;
        while(2*z+1 <= X)
        {
            z = 2*z+1;
            ++y;
        }
        X -= z;
        for(int i=0; i<y; i++)
        {
            v.push_back(counter);
        }
    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}