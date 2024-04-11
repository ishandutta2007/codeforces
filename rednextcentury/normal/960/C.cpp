#include <bits/stdc++.h>
using namespace std;
vector<long long> ret;
int main()
{
    long long x,d;
    cin>>x>>d;
    vector<int> vec;
    for (long long i=1;i<32;i++)
        if ((1LL<<i)&x)
            vec.push_back(i);
    int n = __builtin_popcount(x);
    long long cur=1;
    for (long long i=0;i<n;i++)
        ret.push_back(cur),cur+=d;
    for (int i=0;i<vec.size();i++){
        for (int j=0;j<vec[i];j++)
            ret.push_back(cur);
        cur+=d;
    }
    cout<<ret.size()<<endl;
    for (int i=0;i<ret.size();i++)
        cout<<ret[i]<<' ';
}