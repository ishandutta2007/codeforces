#include<bits/stdc++.h>
using namespace std;

const int MAX=26;
struct node{
    char ch; 
    int deep;
    int total;
    int next[MAX];
}nod[202020];
int cnt;
void init(int rt=0)
{
    cnt=0;
    nod[rt].deep=0;
    nod[rt].total=0;
    for(int i=0;i<MAX;i++)nod[rt].next[i]=-1;
}
void innew(char s[],int rt=0)
{
    if(strlen(s)==0)
    {
        nod[rt].total++;
        return;
    }
    int son=s[0]-'a';
    if(nod[rt].next[son]==-1)
    {
        nod[rt].next[son]=++cnt;

        nod[cnt].deep=nod[rt].deep+1;
        nod[cnt].total=0;
        for(int i=0;i<MAX;i++)nod[cnt].next[i]=-1;
    }
    innew(s+1,nod[rt].next[son]);
}

struct cmp{
    bool operator()(int a,int b)
    {
        return nod[a].deep<nod[b].deep;
    }
};
priority_queue<int,vector<int>,cmp>q[202020];
void dfs(int rt)
{
    if(rt==-1)return;
    while(!q[rt].empty())q[rt].pop();
    for(int i=0;i<MAX;i++)
    {
        int son=nod[rt].next[i];
        dfs(son);
        while(!q[son].empty()){q[rt].push(q[son].top());q[son].pop();} 
    }
    if(rt!=0&&nod[rt].total==0&&!q[rt].empty())
    {
        nod[rt].total++;
        nod[q[rt].top()].total--;
        q[rt].pop();
    }
    if(nod[rt].total==1)
        q[rt].push(rt);
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    string s[202020];
    while(cin>>n)
    {
        init();
        for(int i=0;i<n;i++){
            cin>>s[i];
            innew((char*)s[i].c_str());
        }
        dfs(0);

        int sum=0;
        while(!q[0].empty())
        {
            sum+=nod[q[0].top()].deep;
            q[0].pop();
        }
        cout<<sum<<endl;
    }
}