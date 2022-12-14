#include<bits/stdc++.h>
using namespace std;
int num[1000];
int n,k;
string getSol(char ll, char rr, char op, string s)
{
    int kk=0;
    for (int i=0;i<n;i++)
        if (s[i]==op)
            kk++;
    for (char x=ll+1;x<=rr-1;x++)
        for (int i=0;i<n;i++)
            if (s[i]!=op && s[i]==x && kk<k)
                s[i]=op,kk++;
    for (int i=0;i<n;i++)
        if (s[i]==rr && kk<k)
                kk++,s[i]=op;
    for (int i=n-1;i>=0;i--)
        if (s[i]==ll && kk<k)
            kk++,s[i]=op;
    return s;
}
int main()
{
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0;i<n;i++)
        num[s[i]]++;
    int ans=100000000;
    char ll,rr,op;
    string ret;
    for (char x='0'; x<='9'; x++)
    {
        int cur=num[x];
        int cost=0;
        int st=0;
        char l=x-1,r=x+1;
        while(cur<k)
        {
            st++;
            int av=0;
            if (l>='0')
                av+=num[l];
            if (r<='9')
                av+=num[r];
            if (cur+av>=k)
            {
                cost+=st*(k-cur);
                break;
            }
            else
                cost+=st*av,cur+=av;
            l--,r++;
        }
        if (cost<ans)
            ans=cost,ll=l,rr=r,op=x,ret=getSol(ll,rr,op,s);
        else if (cost==ans)
            ret=min(ret,getSol(l,r,x,s));
    }
    cout<<ans<<endl;

    cout<<ret<<endl;
}