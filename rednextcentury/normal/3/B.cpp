#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > one,two;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,v;
    cin>>n>>v;
    int vv=0;
    for (int i=0;i<n;i++)
    {
        int t,x;
        cin>>t>>x;
        vv+=t;
        if (t==1)one.push_back({x,i});
        else two.push_back({x,i});
    }
    v=min(vv,v);
    long long ret=0;
    sort(one.begin(),one.end());
    if (v%2 && one.size()){
        v--;
        ret+=one.back().first;
        ans.push_back(one.back().second);
        one.pop_back();
    } else if (v%2) v--;
    sort(two.begin(),two.end());
    while(v)
    {
        v-=2;
        if (one.size()>1 && two.size()) {
            int L = one.back().first+one[one.size()-2].first , R = two.back().first;
            if (L<R) ans.push_back(two.back().second),ret+=two.back().first,two.pop_back();
            else {
                for (int x=0;x<2;x++) {
                    ans.push_back(one.back().second),ret+=one.back().first,one.pop_back();
                }
            }
        } else if (one.size()>1) {
                for (int x=0;x<2;x++) {
                    ans.push_back(one.back().second),ret+=one.back().first,one.pop_back();
                }
        } else if (two.size()) {
            ans.push_back(two.back().second),ret+=two.back().first,two.pop_back();
        } else {
            break;
        }
    }
    cout<<ret<<endl;
    for (auto x:ans)cout<<x+1<<' ';
}