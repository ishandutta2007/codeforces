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
int t,n,k,a[MAXN];
string str;
int from[26],to[26];
bool valid[26];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        memset(to,-1,sizeof(to));
        memset(from,-1,sizeof(from));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int ch=str[i]-'a';
            if(to[ch]!=-1) continue;
            int last=ch;
            while(from[last]!=-1) last=from[last];
            for(int j=0;j<26;j++)
            {
                if(cnt<25&&j==last) continue;
                if(from[j]!=-1) continue; 
                to[ch]=j;
                from[j]=ch;
                cnt++;
                break;
            }
        }
        for(int i=0;i<n;i++) printf("%c",'a'+to[str[i]-'a']);
        printf("\n");
    }
    return 0;
}