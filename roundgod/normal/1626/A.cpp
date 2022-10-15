#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
char str[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int n=strlen(str);
        sort(str,str+n);
        printf("%s\n",str);
    }
    return 0;
}