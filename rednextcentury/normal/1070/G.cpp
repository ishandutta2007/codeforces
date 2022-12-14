#include <bits/stdc++.h>
using namespace std;
int a[1000],s[1000],h[1000];
pair<int,int> Move(int l,int r)
{
    if (r>=l)
    {
        pair<int,int> ans;
        int ret=0;
        for (int i=l;i<=r;i++)
        {
            ret+=a[i];
            ans.first=min(ans.first,ret);
        }
        ans.second = ret;
        return ans;
    }
    else
    {
        pair<int,int> ans;
        int ret=0;
        for (int i=l;i>=r;i--)
        {
            ret+=a[i];
            ans.first=min(ans.first,ret);
        }
        ans.second = ret;
        return ans;
    }
}
int ID[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        cin>>s[i]>>h[i],ID[s[i]]=i;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
    {
        vector<pair<int,int> > L;
        vector<pair<int,int> > R;
        for (int j=1;j<=m;j++)
        {
            if (s[j]<i)
                L.push_back({s[j],h[j]});
            else if (s[j]>i)
                R.push_back({s[j],h[j]});
        }
        sort(L.begin(),L.end());
        sort(R.begin(),R.end());
        bool ok=1;
        pair<int,int> bL = {i,1e9};
        vector<int> ans;
        int lID = -1;
        if (L.size()>0)
        {
            bL=L[0];
            lID = ID[L[0].first];
            for (int j=1;j<L.size();j++)
            {
                pair<int,int> p = Move(bL.first,L[j].first);
                if (bL.second+p.first<0)
                    ok=0;
                bL.second+=p.second;
                bL.first= L[j].first;
                if (bL.second > L[j].second) {
                    ans.push_back(ID[L[j].first]);
                } else {
                    ans.push_back(lID);
                    lID = ID[L[j].first];
                    bL = L[j];
                }
            }
        }
        int rID = -1;
        pair<int,int> bR = {i,1e9};
        if (R.size()>0)
        {
            bR=R[R.size()-1];
            rID = ID[R[R.size()-1].first];
            for (int j=((int)R.size()-2);j>=0;j--)
            {
                pair<int,int> p = Move(bR.first,R[j].first);
                if (bR.second+p.first<0)
                    ok=0;
                bR.second+=p.second;
                bR.first= R[j].first;
                if (bR.second > R[j].second) {
                    ans.push_back(ID[R[j].first]);
                } else {
                    ans.push_back(rID);
                    rID = ID[R[j].first];
                    bR = R[j];
                }
            }
        }
        bool ok2=0;
        pair<int,int> p1 = Move(bL.first,i) ,p2;
        if (p1.first+bL.second >= 0 && L.size()>0)
        {
            p2 = Move(bR.first,i+1);
            if (p2.first+bR.second >=0)
                ok2=1,ans.push_back(rID),ans.push_back(lID);
        }
        p1 = Move(bR.first,i);
        if (p1.first+bR.second >= 0 && R.size()>0)
        {
            p2 = Move(bL.first,i-1);
            if (p2.first+bL.second >=0)
                ok2=1,ans.push_back(lID),ans.push_back(rID);
        }
        if (L.size()==0 && R.size()==0)ok2=1;
        if (ok && ok2)
        {
            cout<<i<<endl;
            for (int j=ans.size()-1;j>=0;j--)
            {
                if (ans[j]!=-1)
                    cout<<ans[j]<<' ';
            }
            if (ID[i]!=0)
                cout<<ID[i]<<endl;
            else cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}