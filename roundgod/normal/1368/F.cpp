#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
bool on[MAXN];
vector<int> need;
vector<int> in;
vector<int> out;
void go()
{
    int k=(int)in.size();
    printf("%d",(int)in.size());
    for(auto x:in) 
    {
        printf(" %d",x);
        on[x]=true;
    }
    printf("\n");
    fflush(stdout);
    int z;
    scanf("%d",&z);
    for(int i=z;i<=z+k-1;i++)
    {
        int pos=i>n?i-n:i;
        if(on[pos]) out.push_back(pos);
        on[pos]=false;
    }
}
void surrender()
{
    printf("0\n");
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    if(n<=3) surrender();
    memset(on,false,sizeof(on));
    int opt=-1,ans=0;
    for(int i=2;i<=n;i++)
    {
        int res=0;
        if(n%i==0) res=n/i*(i-1)-(i-1);
        else res=n/i*(i-1)+n%i-1-(i-1);
        if(res>ans)
        {
            ans=res;
            opt=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%opt!=0&&i!=n) need.push_back(i);
    }
    for(int i=0;i<opt;i++) in.push_back(need[i]);
    go();
    for(int i=1;i<ans;i++)
    {
        in.clear();
        out.clear();
        for(int j=0;j<(int)need.size();j++)
        {
            if(in.size()==opt) break;
            if(!on[need[j]]) in.push_back(need[j]);
        }
        if(in.size()!=opt) break;
        else go();
    }
    surrender();
}