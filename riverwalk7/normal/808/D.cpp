#include <iostream>
#include <fstream>
#include <map>
#define MAXN 101000
typedef long long ll;
using namespace std;
ll a[MAXN];
ll sum; int N;
ll cur;
map<ll, bool> m;
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum % 2 == 1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    sum = sum/2;
    m[0] = true;
    for(int i=0; i<N; i++)
    {
        cur += a[i];
        if(m[cur-sum])
        {
            cout<<"YES"<<endl;
            return 0;
        }
        m[a[i]] = true;
    }
    m.clear();
    cur = 0;
    for(int i=N-1; i>=0; i--)
    {
        cur += a[i];
        if(m[cur-sum])
        {
            cout<<"YES"<<endl;
            return 0;
        }
        m[a[i]] = true;
    }
    cout<<"NO"<<endl;
}