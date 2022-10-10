#include <bits/stdc++.h>
using namespace std;

int main()
{
    int stones[14];
    for(int i = 0; i < 14; i++)
    {
        cin >> stones[i];
    }
    long long m = 0;
    for(int i = 0; i < 14; i++)
    {
        long long score = 0;
        int s = stones[i];
        for(int t = 0; t < 14; t++)
        {
            long long f = stones[(i + t + 1)%14] + (s + 13 - t)/14;
            if(t == 13) f -= s;
            if(f%2 == 0) score += f;
        }
        m = max(m, score);
    }
    cout << m;
}