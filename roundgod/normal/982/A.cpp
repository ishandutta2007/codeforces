#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    if(n==1&&str[0]=='0') {puts("No"); return 0;}
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')
        {
            cnt++;
            if(cnt>=3||(i==1&&cnt>=2)||(i==n-1&&cnt>=2))
            {
                puts("No");
                return 0;
            }
        }
        else
        {
            if(cnt==0&&i!=0)
            {
                puts("No");
                return 0;
            }
            cnt=0;
        }
    }
    if(cnt>=3) puts("No"); else puts("Yes");
    return 0;
}