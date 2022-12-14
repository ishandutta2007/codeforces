#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int x;
    cin>>x;
    vector<int> op;
    while(__builtin_popcount(x)!=1)
    {
        int j=0;
        while(j<=25 && ((1<<j)&x)==0)
            j++;
        op.push_back(j);
        x = x^((1<<j)-1);
        x++;
    }
    int j=0;
    while(j<=25 && ((1<<j)&x)==0)
        j++;
    op.push_back(j);
    cout<<op.size()*2-1<<endl;
    for (auto x:op)
        cout<<x<<' ';
}