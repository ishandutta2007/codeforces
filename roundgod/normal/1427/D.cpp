#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,c[MAXN],tmp[MAXN];
vector<vector<int> > ans;
void go(vector<int> &v)
{
    int x=1,y=n;
    for(int i=0;i<(int)v.size();i++)
    {
        for(int j=0;j<v[i];j++) tmp[y-v[i]+1+j]=c[x+j];
        x+=v[i]; y-=v[i]; 
    }
    for(int i=1;i<=n;i++) c[i]=tmp[i];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n/2;i++)
    {
        int l=i,r=n-i+1;
        vector<int> v;
        for(int j=1;j<i;j++) v.push_back(1);
        int p=-1;
        for(int j=1;j<=n;j++) if(c[j]==l) {p=j; break;}
        v.push_back(p-l+1);
        if(r-l+1-(p-l+1)) v.push_back(r-l+1-(p-l+1));
        for(int j=1;j<i;j++) v.push_back(1);
        if(v.size()>1) ans.push_back(v);
        go(v);
        v.clear();
        for(int j=1;j<i;j++) v.push_back(1);
        for(int j=1;j<=n;j++) if(c[j]==r) {p=j; break;}
        v.push_back(p-l+1);
        if(r-l+1-(p-l+2)) v.push_back(r-l+1-(p-l+2));
        v.push_back(1);
        for(int j=1;j<i;j++) v.push_back(1);
        if(v.size()>1) ans.push_back(v);
        go(v);
    }
    printf("%d\n",(int)ans.size());
    for(auto v:ans)
    {
        printf("%d",(int)v.size());
        for(auto x:v) printf(" %d",x);
        puts("");
    }
    return 0;
}