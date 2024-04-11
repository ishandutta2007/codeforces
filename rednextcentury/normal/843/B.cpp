#include<bits/stdc++.h>
using namespace std;
int Rand(int M)
{
    return (((long long)rand())*rand()+3*rand())%M+1;
}
bool vis[1000000];
int getIndex(int M)
{
    int x;
    while(1)
    {
        x=Rand(M);
        if (vis[x])continue;
        vis[x]=1;
        return x;
    }
    return -1;
}
int main()
{
    srand(time(NULL));
    int n,s,x;
    cin>>n>>s>>x;
    if (n<2000)
    {
        while(1)
        {
            cout<<"? "<<s<<endl;
            fflush(stdout);
            int nxt,val;
            cin>>val>>nxt;
            if (val>=x)
            {
                cout<<"! "<<val<<endl;
                fflush(stdout);
                return 0;
            }
            if (nxt==-1)
            {
                cout<<"! -1"<<endl;
                fflush(stdout);
                return 0;
            }
            s=nxt;
        }
    }
    else
    {
        int best,nxt;
        cout<<"? "<<s<<endl;
        fflush(stdout);
        cin>>best>>nxt;
        if (best>=x)
        {
            cout<<"! "<<best<<endl;
            fflush(stdout);
            return 0;
        }
        vis[1]=1;
        for (int i=0;i<998;i++)
        {
            int X=getIndex(n);
            cout<<"? "<<X<<endl;
            fflush(stdout);
            int a,b;
            cin>>a>>b;
            if (a<x && a>best)
                best=a,nxt=b;
        }
        if (nxt==-1)
        {
            cout<<"! -1"<<endl;
            fflush(stdout);
            return 0;
        }
        else
        {
            for (int i=0;i<1000;i++)
            {
                cout<<"? "<<nxt<<endl;
                fflush(stdout);
                int xt,val;
                cin>>val>>xt;
                if (val>=x)
                {
                    cout<<"! "<<val<<endl;
                    fflush(stdout);
                    return 0;
                }
                if (xt==-1)
                {
                    cout<<"! -1"<<endl;
                    fflush(stdout);
                    return 0;
                }
                nxt=xt;
            }
            cout<<"! -1"<<endl;
            fflush(stdout);
        }
    }
}