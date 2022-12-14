#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
vector<int> ret;
void solve(int n,int mul)
{
    if (n==1)
    {
        ret.push_back(mul);
    }
    else if (n==2)
    {
        ret.push_back(mul);
        ret.push_back(mul*2);
    }
    else if (n==3)
    {
        ret.push_back(mul);
        ret.push_back(mul);
        ret.push_back(mul*3);
    }
    else
    {
        for (int i=0;i<n/2+n%2;i++)
            ret.push_back(mul);
        solve(n/2,mul*2);
    }
}
int main()
{
    int n;
    cin>>n;
    solve(n,1);
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';

}