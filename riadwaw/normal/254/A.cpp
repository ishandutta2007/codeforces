#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <stack>
#include <string.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

#define MAX 5001
#define MOD 1000000007
#define ll long long
#define CLR(a,x) memset(a,x,sizeof a)
#define FR(i,n) for(ll i=0;i<n;i++)
#define FAB(i,a,b) for(ll i=a;i<b;i++)
#define FBA(i,b,a) for(ll i=b;i>a;i--)
#define PII pair<int,int>

vector<ll> a[MAX],v;

int main()
{
    freopen("input.txt","r",stdin);       // don't comment it
    freopen("output.txt","w",stdout);     // don't comment it
    ios::sync_with_stdio(false);
    ll n; scanf("%I64d", &n);
    FR(i,(2*n))
    {
        int x;
        scanf("%d",&x);
        a[x].push_back(i+1);
    }

    FAB(i,1,MAX)
    {
        if(!a[i].size()) continue;
        if(a[i].size()&1)
        {
            cout<<-1<<endl;
            return 0;
        }
        v.push_back(i);
    }

    FR(i,v.size())
    {
        ll x=v[i],k=0;
        FR(j,(a[x].size()/2))
        {
            cout<<a[x][k]<<" "<<a[x][k+1]<<'\n';
            k+=2;
        }
    }


    return 0;
}