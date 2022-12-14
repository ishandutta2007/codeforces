#include <bits/stdc++.h>
using namespace std;
int a[1000000];
#define mp make_pair
multiset<int > neg,pos,rneg,rpos;
int main()
{
    int n,len,m;
    cin>>n>>len;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    long long s1=0,s2=0,sz1=0,sz2=0,cur=0;
    long long ans=0;
    for (int i=0;i<n;i++)
    {
        cur+=a[i];
        if (a[i]>0)
        {
            if (sz1<m)
                s1+=a[i],sz1++,pos.insert(a[i]);
            else if (m!=0 && sz1==m)
            {
                if (a[i]>*pos.begin())
                    s1-=*pos.begin(),s1+=a[i],rpos.insert(*pos.begin()),pos.erase(pos.find(*pos.begin())),pos.insert(a[i]);
                else
                    rpos.insert(a[i]);
            }
        }
        if (a[i]<0)
        {
            if (sz2<m)
                s2-=a[i],sz2++,neg.insert(-a[i]);
            else if (m!=0 && sz2==m)
            {
                if (-a[i]>*neg.begin())
                    s2-=*neg.begin(),rneg.insert(*neg.begin()),s2-=a[i],neg.erase(neg.find(*neg.begin())),neg.insert(-a[i]);
                else
                    rneg.insert(-a[i]);
            }
        }
        if (i>=len)
        {
            cur-=a[i-len];
            if (a[i-len]<0)
            {
                int x=-a[i-len];
                if (rneg.find(x)!=rneg.end())
                    rneg.erase(rneg.find(x));
                else
                {
                    if (neg.find(x)!=neg.end())
                    {
                        s2-=x,sz2--,neg.erase(neg.find(x));
                        if (rneg.size())
                        {
                            s2+=*(--rneg.end());
                            sz2++;
                            neg.insert(*(--rneg.end()));
                            rneg.erase(--rneg.end());
                        }
                    }
                }
            }
            else
            {
                int x=a[i-len];
                if (rpos.find(x)!=rpos.end())
                    rpos.erase(rpos.find(x));
                else
                {
                    if (pos.find(x)!=pos.end())
                    {
                        s1-=x,sz1--,pos.erase(pos.find(x));
                        if (rpos.size())
                        {
                            s1+=*(--rpos.end());
                            sz1++;
                            pos.insert(*(--rpos.end()));
                            rpos.erase(--rpos.end());
                        }
                    }
                }
            }
        }
        if (i>=len-1)
            ans=max(ans,max(abs(cur-2*s1),abs(cur+2*s2)));
    }
    cout<<ans<<endl;
}