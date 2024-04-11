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
int q,n;
string str;
int main()
{
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&n);
        cin>>str;
        if(n==2&&str[0]>=str[1])
        {
            puts("NO");
            continue;
        }
        puts("YES");
        puts("2");
        cout<<str.substr(0,1)<<' '<<str.substr(1)<<endl;
    }
    return 0;
}