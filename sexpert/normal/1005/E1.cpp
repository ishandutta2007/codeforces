#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, long long> m1, m2;
    int n, m, aux, ind;
    cin >> n >> m;
    int perm[200010];
    for(int i = 0; i < n; i++)
    {
        cin >> perm[i];
        if(perm[i] == m) ind = i;
    }
    aux = 0;
    for(int i = ind; i >= 0; i--)
    {
        if(perm[i] > m) aux++;
        if(perm[i] < m) aux--;
        m1[aux]++;
    }
    aux = 0;
    for(int i = ind; i < n; i++)
    {
        if(perm[i] > m) aux--;
        if(perm[i] < m) aux++;
        m2[aux]++;
    }
    long long ans;
    /*for(auto p : m1) cout << p.first << " " << p.second << endl;
    cout << endl;
    for(auto p : m2) cout << p.first << " " << p.second << endl;*/
    for(auto p : m1)
    {
        ans += p.second*m2[p.first];
        ans += p.second*m2[p.first - 1];
    }
    cout << ans;
}