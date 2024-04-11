#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAXN 301000
using namespace std;
struct P
{
    int v, id;
    P()
    {
        v = id = 0;
    }
    P(int vv, int iid)
    {
        v = vv; id = iid;
    }
    bool operator <(const P &rhs) const
    {
        return v > rhs.v;
    }
};
int N, K;
int p[MAXN]; //number of proper divisors
int cur, cur2, e;
bool exclude[MAXN];
vector<P> s;
int main()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        for(int j=2; (i*j)<=N; j++)
        {
            p[i*j]++;
        }
    }
    for(int i=1; ; i++)
    {
        cur += p[i];
        if(i>N)
        {
            cout<<"No"<<endl;
            return 0;
        }
        if(cur >= K)
        {
            cur2 = i;
            break;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=cur2/2+1; i<=cur2; i++)
    {
        s.push_back(P(p[i], i));
    }
    sort(s.begin(), s.end());
    for(int i=0; i<s.size(); i++)
    {
        if(cur-s[i].v >= K)
        {
            cur -= s[i].v;
            exclude[s[i].id] = true;
            e++;
        }
    }
    cout<<cur2-e<<endl;
    for(int i=1; i<=cur2; i++)
    {
        if(!exclude[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<""<<endl;
}