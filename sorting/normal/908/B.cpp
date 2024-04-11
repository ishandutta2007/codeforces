#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
string s;
string a[51];
int stx,sty;
int k[4];

bool dfs(int x,int y,int ind)
{
    //cout<<x<<" "<<y<<endl;

    if(x<0 || y<0 || x>=n || y>=m)return 0;
    if(a[x][y]=='E')return 1;
    if(ind==s.size())return 0;
    if(a[x][y]=='#')return 0;


    int p=k[s[ind]-'0'];

    if(p==0)return dfs(x,y+1,ind+1);
    if(p==1)return dfs(x,y-1,ind+1);
    if(p==2)return dfs(x+1,y,ind+1);
    if(p==3)return dfs(x-1,y,ind+1);
}

int main ()
{
    int i,j,res=0;

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]=='S')
            {
                stx=i;
                sty=j;
                break;
            }
        }
    }

    cin>>s;

    k[0]=0;
    k[1]=1;
    k[2]=2;
    k[3]=3;

    for(i=0;i<24;i++)
    {
        res+=dfs(stx,sty,0);

        next_permutation(k,k+4);
    }

    cout<<res<<endl;

    return 0;
}