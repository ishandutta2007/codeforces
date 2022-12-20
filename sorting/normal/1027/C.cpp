#include<iostream>
#include<vector>
#include<algorithm>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

long long curr[10000];
int a[1000001];
vector<long long> v;

int main ()
{
    long long t,n,i,pr,j;
    int res[4];

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    for(t;t>0;t--)
    {
        cin>>n;

        res[0]=1;
        res[1]=1;
        res[2]=100000;
        res[3]=100000;

        for(i=0;i<n;i++)
        {
            cin>>a[i];
            curr[a[i]]++;
        }

        v.clear();

        for(i=0;i<n;i++)
        {
            if(curr[a[i]]>=2)
            {
                if(curr[a[i]]>=4)
                {
                    for(j=0;j<4;j++)
                        res[j]=a[i];
                }
                v.push_back(a[i]);
            }
            curr[a[i]]=0;
        }

        sort(v.begin(),v.end());

        for(i=1;i<v.size();i++)
        {
            if((v[i]+v[i-1])*(v[i]+v[i-1])*res[0]*res[3]<(res[0]+res[3])*(res[0]+res[3])*v[i]*v[i-1])
            {
                res[0]=v[i];
                res[1]=v[i];
                res[2]=v[i-1];
                res[3]=v[i-1];
            }
        }

        for(i=0;i<3;i++)
            cout<<res[i]<<" ";
        cout<<res[i]<<"\n";
    }

    return 0;
}