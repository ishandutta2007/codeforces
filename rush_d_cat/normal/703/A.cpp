#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int n, i, cnt1 = 0, cnt2 = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a>> b;
        if(a > b) cnt1++;
        if(b > a) cnt2++;
    }
    if(cnt1 > cnt2) cout<<"Mishka";
    else if(cnt1 < cnt2) cout<<"Chris";
    else cout <<"Friendship is magic!^^";
    return 0;
}