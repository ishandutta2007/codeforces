#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d %s", &n, s);

        vector < pair <string,int> > v;
        for(int i=0; i<n; i++) {
            string now;
            for(int j=i; j<n; j++) now+=s[j];
            for(int j=0; j<i; j++) now+=s[j];
            if((n-i)&1) reverse(now.begin()+n-i, now.end());
            v.push_back(make_pair(now, i+1));
        }

        sort(v.begin(), v.end());

        cout << v[0].first << '\n';
        cout << v[0].second << '\n';
    }
}