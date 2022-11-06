#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char s[sz];
queue <int> q1,q2;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%s", s);
        for(int i=0; s[i]; i++) {
            int x=s[i]-'0';
            if(x&1) q1.push(x);
            else q2.push(x);
        }

        while(!q1.empty() && !q2.empty()) {
            if(q1.front() < q2.front()) {
                printf("%d", q1.front());
                q1.pop();
            }
            else {
                printf("%d", q2.front());
                q2.pop();
            }
        }

        while(!q1.empty()) {
            printf("%d", q1.front());
            q1.pop();
        }

        while(!q2.empty()) {
            printf("%d", q2.front());
            q2.pop();
        }

        puts("");
    }
}