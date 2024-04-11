#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
#define N 50010
vector<int> A[N];int n,m,f[N][510];ll S=0;
void ff(int x,int fa)
{
    f[x][0]=1;
    for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
        if(*i!=fa)
        {
            ff(*i,x);
            for(int j=0;j<m;j++)S+=(ll)f[x][m-j-1]*f[*i][j];
            for(int j=0;j<m;j++)f[x][j+1]+=f[*i][j];
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),A[x].pb(y),A[y].pb(x);
    ff(1,0);
    cout<<S<<endl;
    return 0;
}