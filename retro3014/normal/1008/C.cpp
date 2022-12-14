#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;
int ans=0;

int main()
{
    scanf("%d", &N);
    int x;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int idx=N-2;
    while(idx>=0 && !v.empty())
    {
        if(v[idx]<v.back())
        {
            v.pop_back();
            ans++;
        }
        idx--;
    }
    printf("%d", ans);
    return 0;
}