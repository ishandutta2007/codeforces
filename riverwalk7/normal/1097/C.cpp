#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#define MAXN 500500
using namespace std;
int d[MAXN]; int e[MAXN];
string s; int N;
vector<int> usable;
map<int, int> u;
int ans;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>s;
        for(int j=0; j<s.size(); j++)
        {
            d[i] += (s[j]=='(' ? 1: -1);
            e[i] = min(d[i], e[i]);
        }
        if(d[i] > e[i] && e[i] < 0)
        {
            //do nothing
        }
        else
        {
            //add depth to usable depot
            usable.push_back(d[i]);
            u[d[i]]++;
        }
    }
    for(int i=0; i<usable.size(); i++)
    {
        if(u[-usable[i]])
        {
            ++ans;
            --u[-usable[i]];
        }
    }
    cout<<ans/2<<endl;
}