#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int N;
int p[MAXN], q[MAXN];
int power[18];
int M;
bool flag;
void solve(int x)
{
    int v = 0;
    for(int i=0; i<=17; i++)
    {
        if(power[i] > x)
        {
            v = power[i]-2-x;
            for(int j=power[i-1]; j<=x; j++)
            {
                swap(p[j], p[power[i]-j-1]);
            }
            break;
        }
    }
    if(v >0)
    solve(v);
}
int main()
{
    cin>>N;
    M = N;
    power[0] = 1;
    for(int i=1; i<=N; i++)
    {
        p[i] = q[i] = i;
    }
    for(int i=1; i<=17; i++)
    {
        power[i] = power[i-1] * 2;
    }
    if(N%2==1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        solve(N);
        for(int i=1; i<N; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<p[N]<<endl;
    }
    for(int i=0; i<=17; i++)
    {
        if(power[i] == N)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(N<=5)
    {
        cout<<"NO"<<endl;
    }
    else if(N==6)
    {
        cout<<"YES"<<endl;
        cout<<"3 6 2 5 1 4"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<"5 3 2 6 7 4 1 ";
        for(int i=8; i<N; i++)
        {
            flag = false;
            for(int j=0; j<=17; j++)
            {
                if(i==(power[j]-1))
                {
                    cout<<(i+1)/2<<" ";
                    flag = true;
                }
            }
            if(!flag)
            {
                cout<<i+1<<" ";
            }
        }
        for(int j=17; j>=0; j--)
        {
            if(N>=power[j]&&N>7)
            {
                cout<<power[j]<<endl;
                return 0;
            }
        }
    }
}