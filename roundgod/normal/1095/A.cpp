#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    int cur=0;
    int tot=1;
    while(cur<n)
    {
        printf("%c",str[cur]);
        cur+=tot;tot++;
    }
    return 0;
}