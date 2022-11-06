#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5;

int a[sz];

int main()
{
    int n,i,j,x;
    cin >> n;
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    stack <int> s;
    for(i=0; i<n; i++) {
        if(!s.empty()) {
            x=s.top();
            if(x%2 == a[i]%2) {
                s.pop();
                continue;
            }
        }
        s.push(a[i]);
    }

    if(s.size()<=1) puts("YES");
    else puts("NO");
}