#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


struct S{
    long long data;
    int idx;
    bool operator <(const S &a)const{
        if(data==a.data)    return idx>a.idx;
        return data>a.data;
    }
};

vector<S> v;
priority_queue<S> pq;

bool sf(S a, S b)
{
    return a.idx<b.idx;
}

int N;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        long long x;
        scanf("%lld", &x);
        pq.push({x, i});
    }
    while(pq.size()>1)
    {
        S x=pq.top();
        pq.pop();
        S y=pq.top();
        pq.pop();
        if(x.data==y.data)
        {
            pq.push({x.data*2, y.idx});
        }
        else
        {
            v.push_back(x);
            pq.push(y);
        }
    }
    v.push_back(pq.top());
    pq.pop();
    sort(v.begin(), v.end(), sf);
    printf("%d\n", (int)v.size());
    for(int i=0; i<v.size(); i++)
    {
        printf("%lld ", v[i].data);
    }
    return 0;
}