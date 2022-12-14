#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll nmax =1e3 +2;
bool vis [nmax][nmax];
ll n, m,sum ;
ll dx[5]= {1,0,0,-1};
ll dy[5]= {0,1,-1,0};
char a[nmax][nmax];
ll res[nmax*nmax],arr[nmax][nmax];


bool check1 ( int i, int j )
{
    if (i >=1 && i <=n  && j >= 1 && j <= m )
        return true;
    return false ;
}


ll check (int i, int j )
{
    ll s=0;
    for (int k =0 ; k <4 ; k++)
    {
        if  (check1(i+dx[k],j+dy[k]) && a[i+dx[k]][j+dy[k]]=='*')
            s+=1;
    }
//cout <<"s"<<s<<endl;
    return s;
}


void dfs (ll i, ll j, ll num )
{
    vis[i][j]=1;
    arr[i][j]=num;
    sum+=check(i,j);
    for (int k =0 ; k <4 ; k++)
    {
        if (check1(i+dx[k],j+dy[k]) && !vis[i+dx[k]][j+dy[k]] && a[i+dx[k]][j+dy[k]]=='.')
            dfs(i+dx[k],j+dy[k],num);
    }


}
int main()
{
    ios_base::sync_with_stdio(0);
    ll k ;
    cin >>n>>m>>k;
    for (int i =1 ; i <=n ; i++ )
    {
        for (int j = 1 ; j <=m ; j++)
            cin >>a[i][j];

    }
    ll num =0;
    for (int i =1 ; i <=n ; i++ )
    {
        for (int j = 1 ; j <=m ; j++)
        {
            if (!vis[i][j] && a[i][j]=='.')
            {
                dfs(i,j, num );
                // cout <<num <<endl;
                res[num]=sum ;
                sum=0;
                num++;

            }


        }
    }
    for (int i =0 ; i <k ; i++)
    {
        ll x,y;
        cin >>x>>y;
        ll g = arr[x][y];
        cout <<res[g] <<endl;


    }
    return 0;
}