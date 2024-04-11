#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int cnt[26];
vector<P> v;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        n=(int)str.size();
        memset(cnt,0,sizeof(cnt));
        v.clear();
        for(int i=0;i<n;i++) cnt[str[i]-'a']++;
        int id=-1;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]==1)
            {
                id=i;
                break;
            }
        }
        if(id!=-1)
        {
            printf("%c",'a'+id);
            for(int i=0;i<26;i++)
            {
                if(i==id) continue;
                for(int j=0;j<cnt[i];j++) printf("%c",'a'+i);
            }
            printf("\n");
        }
        else
        {
            for(int i=0;i<26;i++)
                if(cnt[i]) v.push_back(P(i,cnt[i]));
            sort(v.begin(),v.end());
            int s=0;
            for(auto p:v) s+=p.S;
            if(v[0].S-2<=(s-v[0].S))
            {
                printf("%c%c",'a'+v[0].F,'a'+v[0].F);
                int cnt=v[0].S-2;
                for(int i=1;i<(int)v.size();i++)
                {
                    for(int j=0;j<(int)v[i].S;j++)
                    {
                        printf("%c",'a'+v[i].F);
                        if(cnt)
                        {
                            printf("%c",'a'+v[0].F);
                            cnt--;
                        }
                    }
                }
            }
            else
            {
                if(v.size()==1)
                {
                    for(int i=0;i<v[0].S;i++) printf("%c",'a'+v[0].F);
                }
                else if(v.size()==2)
                {
                    printf("%c",'a'+v[0].F);
                    for(int i=0;i<v[1].S;i++) printf("%c",'a'+v[1].F);
                    for(int i=0;i<v[0].S-1;i++) printf("%c",'a'+v[0].F);
                }
                else
                {
                    printf("%c",'a'+v[0].F);
                    printf("%c",'a'+v[1].F);
                    v[1].S--;
                    for(int i=0;i<v[0].S-1;i++) printf("%c",'a'+v[0].F);
                    printf("%c",'a'+v[2].F);
                    v[2].S--;
                    for(int i=1;i<(int)v.size();i++)
                        for(int j=0;j<(int)v[i].S;j++)
                            printf("%c",'a'+v[i].F);
                }
            }
            printf("\n");
        }
    }
}