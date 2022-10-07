
#include<bits/stdc++.h>
using namespace std;
int a[100009];
int N[100009];
int P[100009];
main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        long long ans = 0;
        set<int> s;
        s.insert(n+1);
        for(int i =1; i <= n; i++){
            cin >> a[i];
            N[i] = i+1;
            P[i] = i-1;
            if(a[i] > 1)s.insert(i);

        }
        for(int i = 1; i <= n; i++){

            ans += max(a[i] - n, 0);
            a[i] = min(a[i], n);
            while(a[i] > 1){
                ans++;
                int x = i;
                while(x <= n){
                    x = *s.lower_bound(x);
                    if(x > n) break;
                    int d = a[x];
                    if(a[x] > 1) a[x]--;
                    if(d == 2) {s.erase(x);}
                    x += d;
                }
            }
        }
        cout<<ans<<endl;

    }
}