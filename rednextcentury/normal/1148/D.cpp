#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int> > v1;
vector<pair<pair<int,int>,int> > v2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        if (a<b)v1.push_back({{a,b},i});
        else v2.push_back({{b,a},i});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if (v1.size()>v2.size()) {
        cout<<v1.size()<<endl;
        reverse(v1.begin(),v1.end());
        for (auto p:v1)
        {
            cout<<p.second<<' ';
        }
        cout<<endl;
    } else {
        cout<<v2.size()<<endl;
        //reverse(v2.begin(),v2.end());
        for (auto p:v2)
        {
            cout<<p.second<<' ';
        }
        cout<<endl;
    }
}