#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<pair<int,int> >ans;
vector<int>lx1[800080],lx2[800080],L1,L2;
int flag1[100010],flag2[100010],trie[800080][26];
int n,len,now,o,nowl,Ans,tot;
char s[800080];

void work(int now,int nowans)
{
    for(int i=0;i<26;i++)if(trie[now][i])work(trie[now][i],nowans+1);
    L1.clear();
    L2.clear();
    for(int i=0;i<(int)lx1[now].size();i++)
        if(!flag1[lx1[now][i]])L1.push_back(lx1[now][i]);
    for(int i=0;i<(int)lx2[now].size();i++)
        if(!flag2[lx2[now][i]])L2.push_back(lx2[now][i]);
    nowl=min(L1.size(),L2.size());
    for(int i=0;i<nowl;i++)
        Ans+=nowans,ans.push_back(make_pair(L1[i],L2[i])),flag1[L1[i]]=1,flag2[L2[i]]=1;        
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        now=0;
        for(int j=0;j<len;j++)
        {
            o=s[j]-'a';
            if(!trie[now][o])trie[now][o]=++tot;
            now=trie[now][o];
            lx1[now].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        now=0;
        for(int j=0;j<len;j++)
        {
            o=s[j]-'a';
            if(!trie[now][o])trie[now][o]=++tot;
            now=trie[now][o];
            lx2[now].push_back(i);
        }
    }
    work(0,0);
    printf("%d\n",Ans);
    L1.clear();
    L2.clear();
    for(int i=1;i<=n;i++)
        if(!flag1[i])L1.push_back(i);
    for(int i=1;i<=n;i++)
        if(!flag2[i])L2.push_back(i);
    for(int i=0;i<(int)L1.size();i++)
        ans.push_back(make_pair(L1[i],L2[i]));
    for(int i=0;i<(int)ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
}