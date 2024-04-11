#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int>A(N, 1);
    vector<int> used(N);
    string s;
    cin>>s;
    for(int i = 0; i < N; ++ i)
    {
        if (s[i]=='<')
        {
            A[i] = -1;
        }
    }
    for(int i = 0; i < N; ++ i)
    {
        int x;
        cin>>x;
        A[i] *= x;
    }
    int cur = 0;
    //used[0] = 1;
    for(int i = 0; i <= N; ++ i)
    {
        //cout<<cur<<endl;
        if (used[cur])
        {
            cout<<"INFINITE"<<endl;
            return 0;
        }
        used[cur] = 1;
        cur += A[cur];
        //cout<<"S"<<cur<<endl;
        if (cur < 0 || cur >= N)
        {
            break;
        }
    }
    cout<<"FINITE"<<endl;
}