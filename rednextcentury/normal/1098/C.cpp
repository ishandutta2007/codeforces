#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<int> ret;
int p[1000000];
vector<int> vec;
void buildSol(int factor)
{
    ret.push_back(0);
    for (int i=0;i+1<ret.size();i++)
    {
        vec.push_back(ret[i]-ret[i+1]);
    }
    int cur=1;
    int c=1;
    int num=0;
    for (int i=1;i<vec.size();i++)
    {
        int st = cur+1;
        for (int j=0;j<vec[i];j++)
        {
            int v = ++cur;
            if (num==factor)num=0,c++;
            p[v]=c;
            num++;
        }
        num=0;
        c=st;
    }
}
bool check(long long n,long long s,int factor)
{
    ret.clear();
    ret.push_back(n);
    ret.push_back(n-1);
    s-=n;
    s-=(n-1);
    if (s<0)return 0;
    long long cur=1;
    long long skipped=0,canSkip=factor-1;
    for (long long i=n-2;i>=1;i--)
    {
        if (skipped<canSkip && (i-1)*(i)/2 >= s)
        {
            skipped++;
        }
        else if (i>s && skipped==canSkip)
            return 0;
        else
        {
            ret.push_back(i);
            s-=i;
            canSkip=(skipped+1)*factor-1;
            skipped=0;
        }
    }
    if (s==0 && ret[ret.size()-1]<=canSkip+1)return 1;
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,s;
    cin>>n>>s;
    int l=1,r=1e9;
    int ans=-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if (check(n,s,mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    if (ans==-1)cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        check(n,s,ans);
        buildSol(ans);
        for (int i=2;i<=n;i++)
            cout<<p[i]<<' ';
    }

}