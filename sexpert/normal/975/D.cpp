#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    map<long long, long long> fs;
    map<pair<int, int>, long long> vecs;
    for(int i = 0; i < n; i++)
    {
        long long x, vx, vy;
        cin >> x >> vx >> vy;
        fs[a*vx - vy]++;
        vecs[make_pair(vx, vy)]++;
    }
    long long res = 0;
    for(map<long long, long long>::iterator it = fs.begin(); it!= fs.end(); it++)
    {
        long long m = it->second;
        res += m*(m - 1);
    }
    for(map<pair<int, int>, long long>::iterator it = vecs.begin(); it!= vecs.end(); it++)
    {
        long long m = it->second;
        res -= m*(m - 1);
    }
    cout << res;
}