#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
string t;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>t;
        int n=(int)t.size();
        bool has0=false,has1=false;
        for(int i=0;i<n;i++)
        {
            if(t[i]=='0') has0=true; else has1=true;
        }
        if(has0&&has1)
        {
            for(int i=0;i<2*n;i++) printf("%c",'0'+(i&1));
            printf("\n");
        }
        else if(has0)
        {
            for(int i=0;i<n;i++) printf("0");
            printf("\n");
        }
        else
        {
            for(int i=0;i<n;i++) printf("1");
            printf("\n");
        }
        
    }
}