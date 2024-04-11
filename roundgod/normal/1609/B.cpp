#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
string str;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    int ans=0;
    for(int i=0;i<n-2;i++) if(str.substr(i,3)=="abc") ans++;
    while(q--)
    {
        int x;
        string c;
        scanf("%d",&x);
        x--;
        cin>>c;
        for(int i=x-2;i<=x;i++)
        {
            if(i<0||i+2>=n) continue;
            if(str.substr(i,3)=="abc") ans--;
        }
        str[x]=c[0];
        for(int i=x-2;i<=x;i++)
        {
            if(i<0||i+2>=n) continue;
            if(str.substr(i,3)=="abc") ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}