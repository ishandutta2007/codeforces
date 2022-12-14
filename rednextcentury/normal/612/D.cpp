# include<bits/stdc++.h>
using namespace std;
int l[1000000];
int r[1000000];
vector<int> v;
unordered_map<int,bool> mp;
unordered_map<int,int> to;
unordered_map<int,int> fr;
int ans[2000001][2];
int m;
int a[2000001];
int bef[2000001];
int b[2000001];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        if (!mp[l[i]])
            v.push_back(l[i]),mp[l[i]]=1;
        if (!mp[r[i]])
            v.push_back(r[i]),mp[r[i]]=1;
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
        to[v[i]]=i,fr[i]=v[i];
    for (int i=0;i<n;i++)
        a[to[l[i]]]++,b[to[r[i]]+1]--;
    int x=0;
    int cl=-1,cr=-1;
    for (int i=0;i<=v.size();i++)
    {
        x+=b[i];
        bef[i]=x;
        x+=a[i];
        if (bef[i]<k)
        {
            if (cl!=-1)
                ans[m][0]=fr[cl],ans[m][1]=fr[cr],m++,cl=-1;
        }
        if (x>=k)
        {
            if (cl==-1)
                cl=cr=i;
            else
                cr++;
        }
    }
    printf("%d\n",m);
    for (int i=0;i<m;i++)
        printf("%d %d\n",ans[i][0],ans[i][1]);
}