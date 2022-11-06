#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

char s[sz];

string ans[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        sort(s, s+n);
        if(k == 1) printf("%s\n", s);
        else if(s[k-1] > s[0]) printf("%c\n", s[k-1]);
        else {
            set <char> st;
            printf("%c", s[0]);
            for(int i=k; i<n; i++) st.insert(s[i]);
            if(st.size() == 1) {
                int rem = n-k;
                int z = (rem + k - 1) / k;
                while(z--) printf("%c", s[k]);
                puts("");
            }
            else {
                for(int i=k; i<n; i++) printf("%c", s[i]);
                puts("");
            }
        }
    }
}