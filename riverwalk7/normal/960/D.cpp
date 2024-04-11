#include <iostream>
#include <fstream>
#define MAXN 100
using namespace std;
typedef long long ll;
int Q; ll T, X, K;
int level;
ll shift[MAXN];
ll power[MAXN];
void compute_level(ll x)
{
    level = 0;
    while(x != 0)
    {
        x /= 2;
        level++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>Q;
    power[1] = 1;
    for(int i=2; i<MAXN; i++)
    {
        power[i] = power[i-1] * 2;
    }
    for(int i=0; i<Q; i++)
    {
        cin>>T;
        if(T == 1)
        {
            cin>>X>>K;
            compute_level(X);
            shift[level] += K;
            shift[level+1] -= (2*K);
        }
        if(T == 2)
        {
            cin>>X>>K;
            compute_level(X);
            shift[level] += K;
        }
        if(T==3)
        {
            cin>>X;
            while(X != 0)
            {
                if(X != 1)
                    cout<<X<<" ";
                else
                    cout<<X<<'\n';
                compute_level(X);
                X += shift[level];
                X = (X % power[level]+power[level])%power[level] + power[level];
                X /= 2;
            }
        }
    }
}