#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 20000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,n,k;
int cnt[MAXN],tot;
int trie[MAXM][2],num[MAXM];
string str,ans;
void ins(string &s)
{
    int rt=1; num[rt]++;
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'0';
        if(!trie[rt][x]) trie[rt][x]=++tot;
        rt=trie[rt][x];
        num[rt]++;
    }
}
int main()
{
    scanf("%d",&q);
    while(q--)
    {
        for(int i=0;i<=tot;i++) trie[i][0]=trie[i][1]=num[i]=0;
        tot=1;
        scanf("%d%d",&n,&k);
        cin>>str;
        for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+(str[i-1]=='0'?1:0);
        int pre=max(0,k-20);
        int len=k-pre;
        set<string> st;
        for(int i=0;i<=n-k;i++)
        {
            if(pre&&(cnt[i+pre]-cnt[i])) continue;
            string s=str.substr(i+pre,len);
            for(int j=0;j<len;j++) s[j]='0'+'1'-s[j];
            if(st.count(s)) continue;
            st.insert(s);
            //cout<<"s="<<s<<endl;
            ins(s);
        }
        ans="";
        for(int i=0;i<pre;i++) ans+='0';
        if(st.size()==(1<<len)) {puts("NO"); continue;}
        puts("YES");
        int now=1;
        for(int i=0;i<len;i++)
        {
            if(num[trie[now][0]]!=(1<<(len-i-1)))
            {
                ans+='0';
                now=trie[now][0];
            }
            else
            {
                ans+='1';
                now=trie[now][1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}