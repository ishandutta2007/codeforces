#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll N;
ll p2, o;
ll sqrtN = 1e9;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>N;
        p2 = 1;
        o = N;
        while(o % 2 == 0)
        {
            p2 *= 2;
            o /= 2;
        }
        if(p2 < sqrtN)
        {
            if(N >= p2*(2*p2+1))
            {
                cout<<2*p2<<endl;
                continue;
            }
        }
        if(o != 1)
        {
            cout<<o<<endl;
            continue;
        }
        cout<<-1<<endl;
    }
}