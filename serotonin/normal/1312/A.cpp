#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;
        if(a%b) puts("NO");
        else puts("YES");
    }
}