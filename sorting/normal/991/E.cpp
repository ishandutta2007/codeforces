#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<long long,bool> > v;
map<vector<pair<long long,bool> >,long long> dp;

long long solve(bool b)
{
     long long i;

     for(i=0;i<=9;i++)
        if(v[i].first)
            break;

     if(i==10)
        return 1;

    if(dp.find(v)!=dp.end())
        return dp[v];

    vector<pair<long long,bool>> v2;

    for(i=0;i<=9;i++)
        v2.push_back(v[i]);

    long long res=0,j;

    for(i=0;i<=9;i++)
        if(v[i].second)
            break;

    if(i==10)
        res=1;

    for(i=b;i<=9;i++)
    {
        if(v[i].first)
        {
            v[i].first--;
            v[i].second=0;

            sort(v.begin(),v.end());

            res+=solve(0);

            for(j=0;j<=9;j++)
                v[j]=v2[j];
        }
    }

    dp[v]=res;

    //for(i=0;i<=9;i++)
    //    cout<<v[i]<<" "<<i<<"\n";
    //cout<<" --- "<<res<<endl;

    return res;
}

int main ()
{
    string s;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;

    long long n=s.size(),i;

    for(i=0;i<=9;i++)
    {
        v.push_back(make_pair(0,0));
    }

    for(i=0;i<n;i++)
    {
        v[s[i]-'0'].first++;
    }

    for(i=0;i<=9;i++)
        if(v[i].first)
            v[i].second=1;

    cout<<solve(true)<<"\n";

    return 0;
}