#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
    int n;
    cin>>n;
    for (int i=2;i<=n;i+=2)
        vec.push_back(i);
    for (int i=1;i<=n;i+=2)
        vec.push_back(i);
    for (int i=2;i<=n;i+=2)
        vec.push_back(i);
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
    cout<<endl;
}