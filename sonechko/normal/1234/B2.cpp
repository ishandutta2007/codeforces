#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

map<int,int> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    deque<int> d;
    for (int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        if (mt[num]==1) {} else
        {
            if ((int)d.size()==k)
            {
                int l=d.front();
                mt[l]=0;
                d.pop_front();
            }
            d.push_back(num);
            mt[num]=1;
        }
    }
    cout<<d.size()<<"\n";
    while (d.size()>0)
    {
        cout<<d.back()<<" ";
        d.pop_back();
    }
}