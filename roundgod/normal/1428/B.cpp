#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
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
        bool f1=true,f2=true;
        for(int i=0;i<n;i++) if(str[i]=='>') f1=false;
        for(int i=0;i<n;i++) if(str[i]=='<') f2=false;
        if(f1||f2) {printf("%d\n",n); continue;}
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='-'||str[(i+1)%n]=='-') cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}