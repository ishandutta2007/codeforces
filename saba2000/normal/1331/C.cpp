#include<bits/stdc++.h>
using namespace std;
//And after happily lived ever they
int p[6] = {4,1,3,2,0,5};
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i <= 5; i++){
        if(n & (1<<i)) ans += (1<<p[i]);
    }
    cout<<ans;
}