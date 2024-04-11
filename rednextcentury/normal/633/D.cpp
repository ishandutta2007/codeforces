#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int a[100000];
long long res[100000];
vector<int> vec;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (++mp[a[i]]==1)
            vec.push_back(a[i]);
    }
    int ans=0;
    for (int i=0;i<vec.size();i++)
    {
        for (int j=0;j<vec.size();j++)
        {
            if (i==j && mp[vec[i]]<2) continue;
            res[0]=vec[i],res[1]=vec[j];
            mp[vec[i]]--,mp[vec[j]]--;
            int i=2;
            while(mp[res[i-1]+res[i-2]] && i<n)
                res[i]=res[i-1]+res[i-2],mp[res[i-1]+res[i-2]]--,i++;
                            ans=max(ans,i);
            i--;
            while(i>=0)
                mp[res[i]]++,i--;
        }
    }
    cout<<ans<<endl;
}