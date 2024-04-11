#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int n,k;
string str;
vector<int> deleted;
int pre[MAXN],suf[MAXN];
bool used[MAXN],pushed[MAXN];
vector<int> update;
int main()
{
    cin>>str;
    n=str.size();
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++)
        pre[i]=i-1,suf[i]=i+1;
    suf[n-1]=-1;
    update.clear();
    int cnt=1;
    for(int i=0;i!=-1;i=suf[i])
        if((suf[i]!=-1&&str[suf[i]]!=str[i])||(pre[i]!=-1&&str[pre[i]]!=str[i]))
        {
            deleted.push_back(i);
            used[i]=true;
        }
    if(deleted.size()==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0;i<deleted.size();i++)
    {
        int x=deleted[i];
        if(pre[x]!=-1) suf[pre[x]]=suf[x];
        if(suf[x]!=-1) pre[suf[x]]=pre[x];
    }
    memset(pushed,false,sizeof(pushed));
    for(int i=0;i<deleted.size();i++)
    {
        int x=deleted[i];
        if(pre[x]!=-1&&!used[pre[x]]&&!pushed[pre[x]])
        {
            pushed[pre[x]]=true;
            update.push_back(pre[x]);
        }
        if(suf[x]!=-1&&!used[suf[x]]&&!pushed[suf[x]])
        {
            pushed[suf[x]]=true;
            update.push_back(suf[x]);
        }
    }
    while(update.size())
    {
        bool f=false;
        deleted.clear();
        for(int i=0;i<update.size();i++)
        {
            int x=update[i];
            if((suf[x]!=-1&&str[suf[x]]!=str[x])||(pre[x]!=-1&&str[pre[x]]!=str[x]))
            {
                deleted.push_back(x);
                f=true;
                used[x]=true;
            }
            pushed[x]=false;
        }
        update.clear();
        if(!f) break;
        cnt++;
        for(int i=0;i<deleted.size();i++)
        {
            int x=deleted[i];
            if(pre[x]!=-1) suf[pre[x]]=suf[x];
            if(suf[x]!=-1) pre[suf[x]]=pre[x];
        }
        for(int i=0;i<deleted.size();i++)
        {
            int x=deleted[i];
            if(pre[x]!=-1&&!used[pre[x]]&&!pushed[pre[x]])
            {
                pushed[pre[x]]=true;
                update.push_back(pre[x]);
            }
            if(suf[x]!=-1&&!used[suf[x]]&&!pushed[suf[x]])
            {
                pushed[suf[x]]=true;
                update.push_back(suf[x]);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}