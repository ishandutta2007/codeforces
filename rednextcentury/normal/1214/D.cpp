#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<long long,long long> > > dp1,dp2;
long long mod = 999939001;
long long mod2= 999974753;
char inp[1000007];
string a[1000007];
pair<long long,long long> operator+(pair<long long,long long> A,pair<long long,long long> B)
{
    return {(A.first+B.first)%mod,(A.second+B.second)%mod2};
}
int n,m;
pair<long long,long long> solve1(int x,int y)
{
    if (x>=n || y>=m || x<0 || y<0)return {0,0};
    if (a[x][y]=='#')return {0,0};
    if (x==0 && y==0)return {1,1};
    if (dp1[x][y].first!=-1)return dp1[x][y];
    return dp1[x][y] = solve1(x-1,y)+solve1(x,y-1);
}
pair<long long,long long> solve2(int x,int y)
{
    if (x>=n || y>=m || x<0 || y<0)return {0,0};
    if (a[x][y]=='#')return {0,0};
    if (x==n-1 && y==m-1)return {1,1};
    if (dp2[x][y].first!=-1)return dp2[x][y];
    return dp2[x][y] = solve2(x+1,y)+solve2(x,y+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
        scanf("%s",inp),a[i]=inp;
    for (int i=0;i<n;i++)
    {
        dp1.push_back(vector<pair<long long,long long> >(m,{-1,-1}));
        dp2.push_back(vector<pair<long long,long long> >(m,{-1,-1}));
    }
    if (solve2(0,0).first==0 && solve2(0,0).first==0)
    {
        cout<<0<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i==0 && j==0)continue;
            if (i==n-1 && j==m-1)continue;
            pair<long long,long long> p;
            p.first = (solve1(i,j).first)*(solve2(i,j).first)%mod;
            p.second = (solve1(i,j).second)*(solve2(i,j).second)%mod2;
            if (p==solve2(0,0))
            {
                cout<<1<<endl;
                return 0;
            }
        }
    }
    cout<<2<<endl;
}