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
string str;
char rep[2];
int main()
{
    while(true)
    {
        cin>>str;
        if(str=="end"||str=="mistake") break;
        int x=1;
        printf("? %d %d\n",0,1); fflush(stdout);
        scanf("%s",rep);
        if(rep[0]=='x')
        {
            printf("! 1\n"); fflush(stdout);
            continue;
        }
        while(true)
        {
            printf("? %d %d\n",x,2*x); fflush(stdout);
            scanf("%s",rep);
            if(rep[0]=='y') {x=x*2; continue;}
            int l=x,r=2*x;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                printf("? %d %d\n",x,mid);
                fflush(stdout);
                scanf("%s",rep);
                if(rep[0]=='x') r=mid; else l=mid;
            }
            printf("! %d\n",r); fflush(stdout);
            break;
        }
    }
    return 0;
}