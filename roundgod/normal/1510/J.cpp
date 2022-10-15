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
vector<P> v;
string str;
int main()
{
    cin>>str;
    n=(int)str.size();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='#')
        {
            cnt++;
        }
        else
        {
            if(cnt>0) v.push_back(P(i-cnt,cnt));
            cnt=0;
        }
    }
    if(cnt>0) v.push_back(P(n-cnt,cnt));
    if(!v.size())
    {
        puts("0");
        return 0;
    }
    int sz=INF;
    sz=min(sz,v[0].F);
    sz=min(sz,n-(v.back().F+v.back().S));
    for(int i=1;i<(int)v.size();i++) sz=min(sz,v[i].F-(v[i-1].F+v[i-1].S)-1);
    for(int k=0;k<=min(sz,4);k++)
    {
        bool f=true;
        for(int i=0;i<=(int)v.size();i++)
        {
            int gap=(i==0?v[i].F:v[i].F-(v[i-1].F+v[i-1].S)-1);
            if(i==(int)v.size()) gap=n-(v.back().F+v.back().S);
            gap-=k;
            if(k==0&&gap!=0) f=false;
            if(k==1&&gap%2==1) f=false;
            if(gap==1) f=false;
        }
        if(f)
        {
            vector<int> ans;
            for(int i=0;i<=(int)v.size();i++)
            {
                int gap=(i==0?v[i].F:v[i].F-(v[i-1].F+v[i-1].S)-1);
                if(i==(int)v.size()) gap=n-(v.back().F+v.back().S);
                gap-=k;
                if(gap>0)
                {
                    if(k==1)
                    {
                        for(int j=0;j<gap/2;j++) ans.push_back(1);
                    }
                    else
                    {
                        if(gap%2==1)
                        {
                            ans.push_back(2);
                            gap-=3;
                        }
                        for(int j=0;j<gap/2;j++) ans.push_back(1);
                    }
                } 
                if(i!=(int)v.size()) ans.push_back(v[i].S+k);
            }
            printf("%d\n",(int)ans.size());
            for(auto x:ans) printf("%d ",x);
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}