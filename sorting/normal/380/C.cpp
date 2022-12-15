#include<iostream>

using namespace std;

struct state
{
    int best,noL,noR;
};

string s;

state st[4000001];

void init(int ind,int l,int r)
{
    if(l==r)
    {
        st[ind].best=0;
        st[ind].noL=0;
        st[ind].noR=0;
        if(s[l-1]=='(')
            st[ind].noL++;
        else
            st[ind].noR++;

        return;
    }

    int mid=(l+r)/2,t;

    init(2*ind,l,mid);
    init(2*ind+1,mid+1,r);

    t=min(st[2*ind].noL,st[2*ind+1].noR);
    st[ind].best=st[2*ind].best+st[2*ind+1].best+t;
    st[ind].noL=st[2*ind].noL+st[2*ind+1].noL-t;
    st[ind].noR=st[2*ind].noR+st[2*ind+1].noR-t;

    return;
}

state query(int ind,int l,int r,int sl,int sr)
{
    state w1,w2,res;

    w1.best=0;
    w1.noL=0;
    w1.noR=0;

    if(l>sr || r<sl)
        return w1;
    if(sl<=l && r<=sr)
        return st[ind];

    int mid=(l+r)/2;

    w1=query(2*ind,l,mid,sl,sr);
    w2=query(2*ind+1,mid+1,r,sl,sr);

    int t;

    t=min(w1.noL,w2.noR);
    res.best=w1.best+w2.best+t;
    res.noL=w1.noL+w2.noL-t;
    res.noR=w1.noR+w2.noR-t;

    return res;
}


int main()
{
    int n,q,i,a,b;

    cin>>s;

    n=s.size();

    init(1,1,n);

    cin>>q;

    for(i=0;i<q;i++)
    {
        cin>>a>>b;

        cout<<query(1,1,n,a,b).best*2<<"\n";
    }

    return 0;
}