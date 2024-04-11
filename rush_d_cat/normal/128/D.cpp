#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int a[100002];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    int cnt = 1;
    a[n+1] = 0;
    for(int i=2;i<=n+1;i++)
    {
        if(a[i] == a[i-1]) cnt++;
        else vec.push_back(cnt), cnt = 1;
        if(a[i] - a[i-1] > 1) 
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(cnt != 1) vec.push_back(cnt);
    vec[0] -= 1, vec[vec.size() - 1] -= 1;
    int ok = 1;
    for (int i = 1; i < vec.size()-1; ++i)
    {
        vec[i] -= 2;
        if(vec[i] < 0) ok = 0;
    }
    for(int i=0;i<vec.size()-1;i++)
    {
        if(vec[i] < 0) ok = 0;
        else {
            vec[i+1] -= vec[i];
            vec[i] -= vec[i];
        }
    }
    if(vec[vec.size()-1] != 0) ok = 0;
    printf("%s\n",ok?"YES":"NO");
}