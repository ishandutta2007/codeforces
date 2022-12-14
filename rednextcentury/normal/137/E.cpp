#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int tree[3000000];
void upd(int x,int l,int r,int v)
{
    if (v<l || v>r)
        return;
    else if (l==r && v==l)
        tree[x]=a[l];
    else
    {
        upd(x*2,l,(l+r)/2,v);
        upd(x*2+1,(l+r)/2+1,r,v);
        tree[x]=min(tree[x*2],tree[x*2+1]);
    }
}
int query(int x,int l,int r,int s,int e)
{
    if (r<s || l>e)
        return 1000000;
    else if (l>=s && r<=e)
        return tree[x];
    else
        return min(query(x*2,l,(l+r)/2,s,e),query(x*2+1,(l+r)/2+1,r,s,e));
}
bool vowel(char x)
{
    x=tolower(x);
    return (x=='a' || x=='e' || x=='o' || x=='u' || x=='i');

}
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int sum=2*n;
    for (int i=0;i<=3*n;i++)
        a[i]=1000000,upd(1,0,3*n,i);
    a[2*n]=0,upd(1,0,3*n,2*n);
    int mx=0,num=0;
    for (int i=1;i<=n;i++)
    {
        if (vowel(s[i-1]))
            sum-=1;
        else
            sum+=2;
        int l=query(1,0,3*n,0,sum);
        a[sum]=min(a[sum],i);
        upd(1,0,3*n,sum);
        if (i-l>mx)
            mx=i-l,num=1;
        else if (i-l==mx)
            num++;
    }
    if (mx==0)
        cout<<"No solution"<<endl;
    else
    cout<<mx<<' '<<num<<endl;
}