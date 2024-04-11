#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
string str;
int row[MAXN],col[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        cin>>str;
        int cnt=0;
        for(int i=0;i<n*m;i++)
        {
            if(str[i]=='1') cnt++;
            if(i>=m&&str[i-m]=='1') cnt--;
            if(cnt==0) row[i]=0; else row[i]=1;
        }
        for(int i=m;i<n*m;i++) row[i]+=row[i-m];
        set<int> s;
        for(int i=0;i<n*m;i++)
        {
            if(str[i]=='1') s.insert(i%m);
            col[i]=(int)s.size();
        }
        for(int i=0;i<n*m;i++) printf("%d ",row[i]+col[i]);
        puts("");
    }
    return 0;
}