#include <bits/stdc++.h>
using namespace std;
bool del[102];
string s;
string k;
int num[12];
void solve(int l,int r)
{
    memset(del,0,sizeof(del));
    memset(num,0,sizeof(num));
    k=s;
    int dir=1;
    int v=l;
    char last=';';
    int id=0;
    while(v>=l && v<=r)
    {
        while(del[v])v+=dir;
        if (v<l || v>r)break;
        if (k[v]>='0' && k[v]<='9')
        {
            num[k[v]-'0']++;
            if (k[v]=='0')del[v]=1;
            else k[v]--;
        }
        else
        {
            if (last=='>' || last=='<')
                del[id]=1;
            if (k[v]=='>')
                dir=1;
            else dir=-1;
        }
        last=k[v];
        id=v;
        v+=dir;
    }

}
int main()
{
    int n,q;
    cin>>n>>q;
    cin>>s;
    for (int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        solve(l,r);
        for (int i=0;i<10;i++)
            cout<<num[i]<<' ';
        cout<<endl;
    }
}