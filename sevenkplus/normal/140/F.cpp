#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
PII A[4200010],B[400010],S[4200010];int AL,BL,SL;
int n,m;PII a[200010];vector<PII> S0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].fi,&a[i].se);
    if(m>=n){puts("-1");return 0;}
    sort(a,a+n);
    for(int k=0;k<=m;k++)
    {
        BL=0;
        for(int i=0;i<n;i++)
        {
            int j=n-i-1-k;
            if(0<=j&&j<n)B[BL++]=mp(a[i].fi+a[j].fi,a[i].se+a[j].se);
            if(!k)continue;
            j=n-i-1+k;
            if(0<=j&&j<n)B[BL++]=mp(a[i].fi+a[j].fi,a[i].se+a[j].se);
        }
        sort(B,B+BL);
        merge(A,A+AL,B,B+BL,S);
        SL=AL+BL;AL=SL;
        memcpy(A,S,(sizeof(PII))*AL);
        for(int i=0,j;i<AL;i=j)
        {
            for(j=i;j<AL&&A[i]==A[j];j++);
            if(j-i>=n-k)S0.pb(A[i]);
        }
    }
    sort(S0.begin(),S0.end());
    S0.erase(unique(S0.begin(),S0.end()),S0.end());
    printf("%d\n",(int)S0.size());
    for(vector<PII>::iterator i=S0.begin();i!=S0.end();i++)
        printf("%.9lf %.9lf\n",i->fi/2.0,i->se/2.0);
    return 0;
}