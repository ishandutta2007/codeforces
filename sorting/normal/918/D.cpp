#include<iostream>
#include<vector>

using namespace std;

vector<int> v[101],c[101];
int n,m;
bool dp[101][101][27];
bool b[101][101][27];

bool solve(int u1,int u2,int pr)
{
    int i;

    if(b[u1][u2][pr])return dp[u1][u2][pr];

    b[u1][u2][pr]=1;

    for(i=0;i<v[u1].size();i++)
    {
        if(c[u1][i]>=pr)
        {
           if(!solve(u2,v[u1][i],c[u1][i]))
           {

               dp[u1][u2][pr]=1;
               return 1;
           }
        }
    }

    dp[u1][u2][pr]=0;
    return 0;
}

int main ()
{
    int i,j,x,y,z;
    char ch;

    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        cin>>x>>y>>ch;

        z=(int)ch-'a';

        v[x].push_back(y);
        c[x].push_back(z);
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(solve(i,j,0))
            {
                cout<<"A";
            }
            else cout<<"B";
        }
        cout<<endl;
    }

    return 0;
}