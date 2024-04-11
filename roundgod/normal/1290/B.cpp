#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
string str;
int cnt[MAXN][26];
int main()
{
    cin>>str;
    n=(int)str.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j];
        cnt[i][str[i-1]-'a']++;
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int c=0;
        for(int j=0;j<26;j++)
            if(cnt[r][j]-cnt[l-1][j]) c++;
        if(c>=3||l==r||str[l-1]!=str[r-1]) puts("Yes"); else puts("No");
    }
    return 0;
}