#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

pair<int,pair<int,int>> p[200001],p2;
priority_queue<int,vector<int>,greater<int> > q;

int main ()
{
    int n,t,i,k;
    long long sum=0;

    cin>>n>>t;

    for(i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second.first;
        p[i].second.second=i+1;
    }

    sort(p,p+n);

    int beg=0,end=n,mid;

    while(end-beg>1)
    {
        mid=(beg+end)/2;

        //cout<<beg<<" "<<end<<endl;

        k=upper_bound(p,p+n,make_pair(mid,make_pair(0,0)))-p;

        if(n-k<mid)
        {
            end=mid-1;
            continue;
        }

        for(i=n-1;i>=k;i--)
        {
            q.push(p[i].second.first);
        }

        sum=0;

        for(i=0;i<mid;i++)
        {
            sum+=q.top();
            q.pop();
        }
        while(!q.empty())q.pop();

        if(sum>t)
        {
            end=mid-1;
            continue;
        }

        beg=mid;
    }

    //cout<<beg<<" "<<end<<endl;

    mid=beg;


    while(beg!=end)
    {
        mid=beg+1;

        k=upper_bound(p,p+n,make_pair(mid,make_pair(0,0)))-p;

        //cout<<k<<endl;

        if(n-k<mid)
        {
            mid=mid-1;
            beg=end;
            continue;
        }

        for(i=n-1;i>=k;i--)
        {
            q.push(p[i].second.first);
        }

        sum=0;

        for(i=0;i<mid;i++)
        {
            sum+=q.top();
            q.pop();
        }
        while(!q.empty())q.pop();

        //cout<<sum<<endl;

        if(sum>t)
        {
            mid=mid-1;
            beg=end;
            continue;
        }

        beg=end;
    }

    k=upper_bound(p,p+n,make_pair(mid,make_pair(0,0)))-p;

    for(i=k;i<n;i++)
    {
        swap(p[i].first,p[i].second.first);
    }

    sort(p+k,p+n);

    cout<<mid<<endl;
    cout<<mid<<endl;

    for(i=k;i<k+mid-1;i++)
    {
        cout<<p[i].second.second<<" ";
    }
    if(mid)cout<<p[i].second.second<<endl;


    return 0;
}