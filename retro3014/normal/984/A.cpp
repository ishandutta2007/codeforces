#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout<<v[(N+1)/2-1];
    return 0;
}