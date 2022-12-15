#include<iostream>
#include<queue>

using namespace std;

priority_queue <int> q;

int main ()
{
    long long n,f,i,k,l,sum=0,p;



    ios::sync_with_stdio(false);

    cin>>n>>f;

    for(i=0;i<n;i++)
    {
        cin>>k>>l;
        p=min(k,l);
        sum+=p;


        q.push(min(2*k,l)-p);
    }

    for(i=0;i<f;i++)
    {
        sum+=q.top();
        q.pop();
    }

    cout<<sum<<endl;

    return 0;
}