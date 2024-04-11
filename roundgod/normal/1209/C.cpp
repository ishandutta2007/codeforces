#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int T,n;
string str;
int color[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cin>>str;
        int pos=-1;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]>str[i+1])
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            for(int i=0;i<n;i++) printf("%d",1);
            puts("");
            continue;
        }
        int x=str[pos]-'0',y=str[pos+1]-'0',mini=10;
        for(int i=0;i<=pos;i++)
        {
            int v=str[i]-'0';
            if(v<=y) color[i]=1;
            else {color[i]=2; mini=min(mini,v);}
        }
        color[pos+1]=1;
        bool f=true;
        for(int i=pos+2;i<n;i++)
        {
            int v=str[i]-'0';
            if(v>=x) {color[i]=2; x=v;}
            else if(v>mini||v<y) f=false;
            else {color[i]=1; y=v;}
        }
        if(!f) puts("-");
        else
        {
            for(int i=0;i<n;i++) printf("%d",color[i]);
            puts("");
        }
    }
}