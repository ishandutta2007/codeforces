#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            int x=str[i];
            if(1+x==last)
            {
                printf("0");
                last=x;
            }
            else
            {
                printf("1");
                last=1+x;
            }
        }
        puts("");
    }
    return 0;
}