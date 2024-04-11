#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);
    int N, K, Q;
    cin>>N>>K>>Q;
    vector<int> A(N);
    for(int i = 0; i < N; ++ i)
    {
        cin>>A[i];
    }
    set<pair<int, int> > Set;
    vector<int> used(N);
    for(int u = 0; u < Q; ++ u)
    {
        int z;
        cin>>z;
        int x;
        cin>>x;
        x--;
        if (z == 1)
        {
            Set.insert(make_pair(A[x], x));
            used[x] = 1;
            if (Set.size() > K)
            {
                int y = Set.begin()->second;
                used[y] = 0;
                Set.erase(Set.begin());
            }
        }
        else
        {
            if (used[x])
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }


}