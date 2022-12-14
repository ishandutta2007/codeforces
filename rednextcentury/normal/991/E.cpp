#include<bits/stdc++.h>
using namespace std;
long long fact[100];
int cnt[10];
int cur[10];
long long ret=0;
bool can=0;
void solve(int i)
{
    if (i==10)
    {
        int tot=0;
        for (int j=0;j<10;j++)
            tot+=cur[j];
        long long num = fact[tot];
        for (int j=0;j<10;j++)
            num/=fact[cur[j]];
        ret+=num;
    }
    else
    {
        if (cnt[i]==0){cur[i]=0,solve(i+1);return;}
        int st=1;
        if (can && i==0)st=0;
        for (int j=st;j<=cnt[i];j++)
        {

            cur[i]=j;
            solve(i+1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    fact[0]=1;
    for (int i=1;i<=19;i++)
        fact[i]=fact[i-1]*i;
    for (auto x:s)
        cnt[x-'0']++;
    solve(0);
    long long A = ret;
    ret=0;
    if (cnt[0]==0)
    {
        cout<<A<<endl;
        return 0;
    }
    can=1;
    cnt[0]--;
    solve(0);
    A-=ret;
    cout<<A<<endl;
}