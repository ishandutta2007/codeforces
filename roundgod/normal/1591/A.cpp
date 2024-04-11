#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int h=1,last=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(h==-1) continue;
            if(last==0&&x==0) h=-1;
            else if(x==0) last=0;
            else 
            {
                if(last==1) h+=5; else h++;
                last=1;
            }
        }
        printf("%d\n",h);
    }
    return 0;
}