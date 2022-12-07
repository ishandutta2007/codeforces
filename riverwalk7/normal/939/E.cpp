#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
int Q, h;
ll x, v, avg, c;
double l, m;
priority_queue<ll, vector<ll>, std::greater<ll> > q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>Q;
    for(int i=0; i<Q; i++)
    {
        cin>>h;
        if(h==1)
        {
            cin>>x;
            if(c==0)
            {
                c = 1;
                avg = v = x;
            }
            else if(x>v)
            {
                avg += (x-v);
                q.push(v);
                v = x;
            }
            else
            {
                q.push(x);
            }
            while(!q.empty()&&q.top()*c < avg)
            {
                avg = (avg+q.top());
                c = c+1;
                q.pop();
            }
        }
        if(h==2)
        {
            l = v; m = (double)(avg)/(double)(c);
            cout<<fixed<<setprecision(7)<<l-m<<endl;
        }
    }
}