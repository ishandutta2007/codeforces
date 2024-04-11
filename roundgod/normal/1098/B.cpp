#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
string str;
int curans,num;
mat A,best,now;
int comb[6][4]=
{
    0,1,2,3,
    0,2,1,3,
    0,3,1,2,
    1,2,0,3,
    1,3,0,2,
    2,3,0,1,
};
void checkrow()
{
    for(int i=0;i<6;i++)
    {
        int cur=0;
        for(int j=0;j<n;j++)
        {
            int even0=0,odd0=0,even1=0,odd1=0;
            int id0=comb[i][(j&1)*2],id1=comb[i][(j&1)*2+1];
            for(int k=0;k<m;k++)
            {
                if(A[j][k]==id0) {if(k&1) odd0++; else even0++;}
                if(A[j][k]==id1) {if(k&1) odd1++; else even1++;}
            }
            if(m-odd0-even1<m-odd1-even0)
            {
                for(int k=0;k<m;k++) now[j][k]=(k&1)?id0:id1;
            }
            else for(int k=0;k<m;k++) now[j][k]=(k&1)?id1:id0;
            cur+=min(m-odd0-even1,m-odd1-even0);
        }
        if(cur<curans) {curans=cur; best=now;}
    }
}
void checkcol()
{
    for(int i=0;i<6;i++)
    {
        int cur=0;
        for(int j=0;j<m;j++)
        {
            int even0=0,odd0=0,even1=0,odd1=0;
            int id0=comb[i][(j&1)*2],id1=comb[i][(j&1)*2+1];
            for(int k=0;k<n;k++)
            {
                if(A[k][j]==id0) {if(k&1) odd0++; else even0++;}
                if(A[k][j]==id1) {if(k&1) odd1++; else even1++;}
            }
            if(n-odd0-even1<n-odd1-even0)
            {
                for(int k=0;k<n;k++) now[k][j]=(k&1)?id0:id1;
            }
            else for(int k=0;k<n;k++) now[k][j]=(k&1)?id1:id0;
            cur+=min(n-odd0-even1,n-odd1-even0);
        }
        if(cur<curans) {curans=cur; best=now;}
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    A.resize(n);now.resize(n);best.resize(n);
    for(int i=0;i<n;i++) A[i].resize(m),now[i].resize(m),best[i].resize(m);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<m;j++)
        {
            if(str[j]=='A') A[i][j]=0;
            else if(str[j]=='T') A[i][j]=1;
            else if(str[j]=='C') A[i][j]=2;
            else A[i][j]=3;
        }
    }
    curans=INF;
    checkrow();checkcol();
    assert(curans!=INF);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(best[i][j]==0) printf("A");
            else if(best[i][j]==1) printf("T");
            else if(best[i][j]==2) printf("C");
            else printf("G");
        }
        puts("");
    }
    return 0;
}