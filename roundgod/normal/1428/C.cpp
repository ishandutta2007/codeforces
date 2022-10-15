#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int st[MAXN],tot;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        n=(int)str.size();
        tot=0;
        for(int i=0;i<n;i++)
        {
            st[tot++]=str[i]-'A';
            if(tot>1&&((st[tot-1]==1&&st[tot-2]==0)||(st[tot-1]==1&&st[tot-2]==1))) tot-=2;
        }
        printf("%d\n",tot);
    }
    return 0;
}