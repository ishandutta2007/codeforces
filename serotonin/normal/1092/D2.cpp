#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5;

int a[sz];

int main()
{
    int n,i,j,x,y=0,b=0;
    cin >> n;
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    stack <int> s;
    for(i=0; i<n; i++) {
        if(!s.empty()) {
            x=s.top();
            if(x==a[i]) {
                s.pop();
                if(!s.empty()) y=s.top();
                if(s.empty() || x<y) {
                    b=max(b,x);
                    continue;
                }
                else s.push(x);
            }
        }
        s.push(a[i]);
    }

    if(s.empty()) puts("YES");
    else if(s.size()==1 && s.top()>=b) puts("YES");
    else puts("NO");
}