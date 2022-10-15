#include<bits/stdc++.h>
#define MAXN 200005
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
        int pos=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(str[i]-'0'+str[i+1]-'0'>=10)
            {
                pos=i;
                break;
            }
        }
        if(pos==-1) pos=0;
        for(int i=0;i<pos;i++) printf("%c",str[i]);
        printf("%d",str[pos]-'0'+str[pos+1]-'0');
        for(int i=pos+2;i<n;i++) printf("%c",str[i]);
        puts("");
    }
    return 0;
}