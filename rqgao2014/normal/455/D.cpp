#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#define ll long long
#define si 400
#define pb push_back
#define pf push_front
using namespace std;

deque<int> q[500];
int n,a[100005],lans,tot;
int num[405][100005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        q[(i+si-1)/si].pb(a[i]);
        num[(i+si-1)/si][a[i]]++;
    }
//  for(int i=1;q[i].size();i++)
//     printf("%d\n",q[i].size());
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        l=(l+lans-1)%n+1;
        r=(r+lans-1)%n+1;
        if(l>r) swap(l,r);
        int xl,xr,nl,nr;
        xl=(l+si-1)/si;xr=(r+si-1)/si;
        nl=(l-1)%si;nr=(r-1)%si;
        if(t-2){
            
            int tmp=q[xr][nr];
            q[xr].erase(q[xr].begin()+nr);
            num[xr][tmp]--;
            q[xl].insert(q[xl].begin()+nl,tmp);
            num[xl][tmp]++;
            for(int j=xl;j<xr;j++){
                if(q[j].size()>si){
                    num[j][q[j].back()]--;
                    num[j+1][q[j].back()]++;
                    q[j+1].pf(q[j].back());q[j].pop_back();
                }
            }
        }
        else{
            int k;
            scanf("%d",&k);
            k=(k+lans-1)%n+1;
            int ans=0;
            if(xl==xr){
                for(int j=nl;j<=nr;j++)
                 ans+=!(q[xl][j]-k);
            }
            else{
                for(int j=xl+1;j<xr;j++)
                    ans+=num[j][k];
                for(int j=nl;j<q[xl].size();j++)
                    ans+=!(q[xl][j]-k);
                for(int j=0;j<=nr;j++)
                ans+=!(q[xr][j]-k);
            }
            lans=ans;
//          printf("Ans%d : %d\n",++tot,ans);
            printf("%d\n",ans);
        }
    }
    return 0;
}