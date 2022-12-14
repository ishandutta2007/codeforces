#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<pair<int,char> > vec;
    for (int i=0;i<4;i++)
    {
        char x;
        cin>>x>>x;
        string s;
        cin>>s;
        vec.push_back({(int)s.size(),char('A'+i)});
    }
    sort(vec.begin(),vec.end());
    int l=0,r=0;
    if (vec[0].first*2<=vec[1].first)
        l=1;
    if (vec[3].first>=vec[2].first*2)
        r=1;
    if (l==1 && r==0)cout<<vec[0].second<<endl;
    else if (r==1 && l==0)cout<<vec[3].second<<endl;
    else cout<<'C'<<endl;
}