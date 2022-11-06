#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=505;

int ara[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> a;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            a.push_back(x&1);
        }
        sort(a.begin(), a.end());
        if(a[0]==a.back()) puts("YES");
        else puts("NO");
    }
}