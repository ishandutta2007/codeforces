#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        scanf("%d %d", &n, &k);
        scanf("%s", s+1);

        vector < pair <int,int> > ans;
        for(int i=1; i<k; i++) {
            int x=i<<1;
            for(int j=x-1; j<=n; j++) {
                if(s[j]=='(') {
                    ans.push_back(make_pair(x-1, j));
                    reverse(s+x-1, s+j+1);
                    break;
                }
            }
            for(int j=x; j<=n; j++) {
                if(s[j]==')') {
                    ans.push_back(make_pair(x, j));
                    reverse(s+x, s+j+1);
                    break;
                }
            }
        }

        int x=(k<<1)-1;
        for(int i=0; i<n/2-(k-1); i++, x++) {
            for(int j=x; j<=n; j++) {
                if(s[j]=='(') {
                    ans.push_back(make_pair(x, j));
                    reverse(s+x, s+j+1);
                    break;
                }
            }
        }

        for(int i=0; i<n/2-(k-1); i++, x++) {
            for(int j=x; j<=n; j++) {
                if(s[j]==')') {
                    ans.push_back(make_pair(x, j));
                    reverse(s+x, s+j+1);
                    break;
                }
            }
        }

        printf("%d\n", ans.size());
        for(auto it : ans) printf("%d %d\n", it.first, it.second);
    }
}