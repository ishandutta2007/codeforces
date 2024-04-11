#include<iostream>
#include<set>

using namespace std;

set<unsigned long long> Set;

int main ()
{
    unsigned long long x,y,l,r,i,j,st1,st2,res=0,pr;

    cin>>x>>y>>l>>r;

    st1=1;

    for(i=0;i<=64;i++)
    {

        st2=1;
        for(j=0;j<=64;j++)
        {
           // cout<<st1<<" "<<st2<<endl;
            if(st1+st2>=l && st1+st2<=r)
            {
                Set.insert(st1+st2);
            }
            if((r-st1)/y<st2)break;
            st2*=y;
        }
        if(r/x<st1)break;
        st1*=x;
    }

    pr=l-1;

    for(set<unsigned long long> :: iterator it=Set.begin();it!=Set.end();it++)
    {
        res=max(res,*it-pr-1);
        pr=*it;
    }
    res=max(res,r-pr);

    cout<<res<<endl;

    return 0;
}