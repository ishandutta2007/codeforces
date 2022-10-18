#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 11;
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for (int i=1; i<=1000; i++)
    if (n-i<i+1) {v.push_back(n); break;} else {v.push_back(i); n-=i;}
    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}