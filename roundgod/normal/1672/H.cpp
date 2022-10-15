#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[2][MAXN];
string str;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    for(int i=0;i<n-1;i++)
    {
        a[0][i+1]=a[0][i]; a[1][i+1]=a[1][i];
        if(str[i]==str[i+1]) a[str[i]-'0'][i+1]++;
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        r--; l--;
        printf("%d\n",1+max(a[0][r]-a[0][l],a[1][r]-a[1][l]));
    }
    return 0;
}