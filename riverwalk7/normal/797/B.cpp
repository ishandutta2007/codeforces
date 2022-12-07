#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 100100
using namespace std;
int N;
int ans, x;
vector<int> a;
vector<int> b;
bool comp(int a, int b)
{
    return a>b;
}
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        if(x%2==0)
        {
            a.push_back(x);
        }
        else
        {
            b.push_back(x);
        }
    }
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>0)
        {
            ans += a[i];
        }
    }
    sort(b.begin(), b.end(), comp);
    if(b.size()>0)
    {
        ans += b[0];
        for(int i=1; i<b.size()-1; i+=2)
        {
            if(b[i] + b[i+1] > 0)
            {
                ans += (b[i] + b[i+1]);
            }
        }
    }
    cout<<ans<<endl;
}