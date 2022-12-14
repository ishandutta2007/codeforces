#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> Q1,Q2;
    for (int i=1;i<=100;i++)
        Q1.push_back(i<<7);
    for (int i=1;i<=100;i++)
        Q2.push_back(i);
    cout<<'?';
    for (int i=0;i<Q1.size();i++)
        cout<<' '<<Q1[i];
    cout<<endl;
    fflush(stdout);
    int ret1;
    cin>>ret1;
    cout<<'?';
    for (int i=0;i<Q2.size();i++)
        cout<<' '<<Q2[i];
    cout<<endl;
    fflush(stdout);
    int ret2;
    cin>>ret2;
    ret2>>=7;
    for (int i=7;i<14;i++)
        if (ret1&(1<<i))ret1-=(1<<i);
    ret2<<=7;
    ret2+=ret1;
    cout<<"! "<<ret2<<endl;
    fflush(stdout);
}