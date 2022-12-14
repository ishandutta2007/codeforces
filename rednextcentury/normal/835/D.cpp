#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > v[1000000];
int t[5001][5001];
int ret[100000];
void Add(int x)
{
    ret[1]++;
    ret[x+1]--;
}
int main()
{
    string s;
    int n;
    cin>>s;
    n=s.size();
    for (int i=0;i<s.size();i++)
    {
        if (i>0 && s[i-1]==s[i])
            v[2].push_back(make_pair(i-1,i)),t[i-1][i]=2,ret[1]++,ret[3]--;
        v[1].push_back(make_pair(i,i));
        t[i][i]=1;
        ret[1]++,ret[2]--;
    }
    for (int i=1;i+1<n;i++)
    {
        for (int j=0;j<v[i].size();j++)
        {
            int l = v[i][j].first;
            int r = v[i][j].second;
            l--; r++;
            if (l<0 || r>=s.size())
                continue;
            if (s[l]!=s[r])
                continue;
            int l1 = l, r1 = (l+r)/2 -(r-l+1)%2;
            int l2 = r1+1+(r-l+1)%2, r2 = r;
            if (t[l1][r1]>0 && t[l2][r2]>0 && t[l1][r1]==t[l2][r2])
            {
                t[l][r]=t[l1][r1]+1;
                Add(t[l][r]);
                v[i+2].push_back(make_pair(l,r));
            }
            else
                t[l][r]=1 , Add(1),v[i+2].push_back(make_pair(l,r));
        }
    }
    for (int i=1;i<=n;i++)
        ret[i]+=ret[i-1],cout<<ret[i]<<" ";
}