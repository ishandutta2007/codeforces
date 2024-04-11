#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > prob[1000000];
set<pair<int,int> > S;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,T;
    cin>>n>>T;
    for (int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        prob[a].push_back(make_pair(b,i));
    }
    for (int i=1;i<=n;i++)
        if (prob[i].size()>0)
            sort(prob[i].begin(),prob[i].end());
    int sum = 0;
    int best = 0;
    for (int i=n;i>=1;i--)
    {
        while(S.size()>i){
            sum-=(*(--S.end())).first;
            S.erase(--S.end());
        }
        for (int j=0;j<prob[i].size();j++)
        {
            if (S.size()<i && sum+prob[i][j].first<=T){
                sum+=prob[i][j].first;
                S.insert(prob[i][j]);
            }
            else if (S.size() && S.size()<i && (*(--S.end())).first > prob[i][j].first)
            {
                sum-=(*(--S.end())).first;
                S.erase(--S.end());
                sum+=prob[i][j].first;
                S.insert(prob[i][j]);
            }
        }
        best=max(best,(int)S.size());
    }

    S.clear();
    sum=0;

    for (int i=n;i>=1;i--)
    {
        while(S.size()>i){
            sum-=(*(--S.end())).first;
            S.erase(--S.end());
        }
        for (int j=0;j<prob[i].size();j++)
        {
            if (S.size()<i && sum+prob[i][j].first<=T){
                sum+=prob[i][j].first;
                S.insert(prob[i][j]);
            }
            else if (S.size() && S.size()<i && (*(--S.end())).first > prob[i][j].first)
            {
                sum-=(*(--S.end())).first;
                S.erase(--S.end());
                sum+=prob[i][j].first;
                S.insert(prob[i][j]);
            }
        }
        if (S.size()==best)
        {
            cout<<S.size()<<endl;
            cout<<S.size()<<endl;
            int x = S.size();
            for (int j=0;j<x;j++)
            {
                cout<<(*S.begin()).second<<' ';
                S.erase(S.begin());
            }
            cout<<endl;
            return 0;
        }
    }
}