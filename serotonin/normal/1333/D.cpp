#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3005;

char s[sz];

int a[sz];

vector < vector <int> > ans;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for(int i=0; s[i]; i++) a[i+1] = s[i] == 'R';

    ll cnt = 0;
    for(int i=0; i<n; i++) {
        vector <int> now;
        for(int j=n-1; j>0; j--) {
            if(a[j]>a[j+1]) {
                swap(a[j], a[j+1]);
                cnt++;
                now.push_back(j--);
            }
        }
        if(now.empty()) break;
        ans.push_back(now);
    }

    if(cnt < k || ans.size() > k) puts("-1");
    else {
        int m = k - ans.size();
        for(auto v : ans) {
            for(int i=0; i<v.size(); i++) {
                if(m) {
                    printf("1 %d\n", v[i]);
                    m--;
                    if(i+1==v.size()) m++;
                }
                else {
                    printf("%d", v.size() - i);
                    for(int j=i; j<v.size(); j++) printf(" %d", v[j]);
                    puts("");
                    break;
                }
            }
        }
    }
}