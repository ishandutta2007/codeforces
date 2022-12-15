#include<iostream>
#include<vector>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#define endl "\n"

using namespace std;

int a[200007];
int res[200007];
bool used[200007];
vector<int> notSpotted;
bool spotted[200007];
int n;

bool rt[200007];
int posRT[200007];

int rmq[200007][21];
int logg[200007];

void rmqInit()
{
    int i,st,j;

    for(i=2;i<=200001;i*=2)
        logg[i]=1;
    for(i=2;i<=200001;i++)
        logg[i]+=logg[i-1];

    //cout<<"2"<<endl;

    for(i=0;i<n;i++)
        rmq[i][0]=res[i];

    for(i=1,st=1;i<21;i++,st*=2)
    {
        //cout<<i<<endl;
        for(j=0;j<n;j++)
        {
            if(rmq[j][i-1]<rmq[min(n-1,j+st)][i-1])
                rmq[j][i]=rmq[j][i-1];
            else
                rmq[j][i]=rmq[min(n-1,j+st)][i-1];
        }
    }
}

int doRMQ(int x,int y)
{

    int res1,res2;
    res1=rmq[x][logg[y-x+1]];
    res2=rmq[y-(1<<(logg[y-x+1]))+1][logg[y-x+1]];

    return min(res1,res2);
}

int dfs(int pos,short b)
{
    if(a[pos])
        return a[pos];
    if(used[pos])
        return res[pos];

    int i;
    if(b==0)
    {
        if(pos!=0)
            res[pos]=dfs(pos-1,0);
    }
    if(b==1)
    {
        if(pos!=n-1)
            res[pos]=dfs(pos+1,1);
    }
    if(b==2)
    {
        if(pos!=0)
        {
            res[pos]=dfs(pos-1,0);
            if(res[pos]==0)
                res[pos]=dfs(pos+1,1);
        }
        else
        {
            res[pos]=dfs(pos+1,1);
        }
    }


    if(res[pos])used[pos]=1;

    return res[pos];
}

int main ()
{
    int q,i,mini,maxi;

    cin>>n>>q;

    for(i=0;i<n;i++)
        cin>>a[i];

    if(n==1)
    {
        if(a[0]==0)
            a[0]=q;
        if(a[0]!=q)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<q<<endl;
        }

        return 0;
    }



    for(i=0;i<n;i++)
        spotted[a[i]]=1;

    for(i=1;i<=q;i++)
        if(!spotted[i])
            notSpotted.push_back(i);

    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            if(!notSpotted.empty() && notSpotted.back()==q)
            {
                res[i]=notSpotted.back();
                notSpotted.pop_back();
                used[i]=1;
            }
            else
            {
                if(!used[i])
                {
                    res[i]=dfs(i,2);
                }
            }
        }
        else
            res[i]=a[i];
    }

    ///check res

    rmqInit();

    for(i=0;i<n;i++)
    {
        if(rt[a[i]])
        {
            if(doRMQ(posRT[a[i]],i)<a[i])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else
        {
            rt[a[i]]=1;
            posRT[a[i]]=i;
        }
    }

    mini=res[0];
    maxi=res[0];

    for(i=1;i<n;i++)
    {
        mini=min(mini,res[i]);
        maxi=max(maxi,res[i]);
    }

    if(maxi!=q)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    for(i=0;i<n-1;i++)
    {
        cout<<res[i]<<" ";
    }

    cout<<res[i]<<endl;

    return 0;
}