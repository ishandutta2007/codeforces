#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000+2];
int main()
{
    int n, i ,cnt = 0,res = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] > a[i - 1]) cnt ++;
        else cnt = 1;
        res = max(res, cnt);
    }
    cout << res <<endl;
    return 0;
}