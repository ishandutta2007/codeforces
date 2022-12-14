#include<bits/stdc++.h>
using namespace std;
int trie[4000000][2];
int  cnt[4000000];
int num=1;
int tmp[40];
void Upd(int p,int x)
{
    for (int i=0;i<30;i++)
        tmp[i]=p%2,p/=2;
    reverse(tmp,tmp+30);
    int v=0;
    for (int i=0;i<30;i++)
    {
        if (i!=0)
            cnt[v]+=x;
        if (trie[v][tmp[i]]==0)
        {
            trie[v][tmp[i]]=num;
            v=num++;
        }
        else
            v=trie[v][tmp[i]];
    }
    cnt[v]+=x;
}
int a[40];
int b[40];
int Count(int l,int p)
{
    for (int i=0;i<30;i++)
        a[i]=l%2,b[i]=p%2,l/=2,p/=2;
    reverse(a,a+30);
    reverse(b,b+30);
    int v=0;
    int ret=0;
    for (int i=0;i<30;i++)
    {
        if (a[i]==1 && b[i]==1)
            ret+=cnt[trie[v][1]],v=trie[v][0];
        else if (a[i]==1 && b[i]==0)
            ret+=cnt[trie[v][0]],v=trie[v][1];
        else if (a[i]==0 && b[i]==0)
            v=trie[v][0];
        else
            v=trie[v][1];
        if (v==0)break;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int typ;
        cin>>typ;
        if (typ==1)
        {
            int p;
            cin>>p;
            Upd(p,1);
        }
        else if (typ==2)
        {
            int p;
            cin>>p;
            Upd(p,-1);
        }
        else
        {
            int l,p;
            cin>>p>>l;
            cout<<Count(l,p)<<endl;
        }
    }
}