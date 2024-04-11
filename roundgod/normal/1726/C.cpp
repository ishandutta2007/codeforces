#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int s[MAXN];
vector<int> save[MAXN];
int last[2*MAXN],L[MAXN],st[MAXN],tot;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=n+1;
        n*=2;
        cin>>str;
        for(int i=0;i<n-1;i++) if(str[i]=='('&&str[i+1]==')') ans--;
        printf("%d\n",ans);
    }
    return 0;
}