#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,c[MAXN*MAXN];
vector<int> pos[MAXN];
int L[MAXN],R[MAXN];
bool used[MAXN];
int pt[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n*k;i++) 
    {
        scanf("%d",&c[i]);
        pos[c[i]].push_back(i);
    }
    for(int i=1;i<=(n+k-2)/(k-1);i++)
    {
        int st=(i-1)*(k-1)+1,ed=min(i*(k-1),n);
        int cur=0;
        memset(used,false,sizeof(used));
        for(int j=1;j<=ed-st+1;j++) pt[j]=0;
        for(int j=1;j<=ed-st+1;j++)
        {
            int mini=INF,id=-1,l=-1,r=-1;
            for(int d=1;d<=ed-st+1;d++)
            {
                if(used[d]) continue;
                int c=st+d-1;
                while(pt[d]<(int)pos[c].size()-1&&pos[c][pt[d]]<=cur) pt[d]++;
                if(pt[d]<(int)pos[c].size()-1&&pos[c][pt[d]+1]<mini)
                {
                    mini=pos[c][pt[d]+1];
                    id=d;
                    l=pos[c][pt[d]];
                    r=pos[c][pt[d]+1];
                }
            }            
            assert(mini!=INF);
            L[c[l]]=l; R[c[r]]=r;
            used[id]=true;
            cur=r;
        }
    }
    for(int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
    return 0;
}