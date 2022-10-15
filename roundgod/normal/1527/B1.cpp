#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int cnt=0;
        for(int i=0;i<n;i++) if(str[i]=='0') cnt++;
        if((n&1)&&(str[n/2]=='0'))
        {
            if(cnt>1) puts("ALICE"); else puts("BOB");
        }
        else
        {
            if(cnt) puts("BOB"); else puts("DRAW");
        }
    }
}