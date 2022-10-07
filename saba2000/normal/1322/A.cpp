#include<bits/stdc++.h>
#define mid ((l+r)/2)
#define ll long long
using namespace std;
int s[1000009],a[1000009];
main(){
    int n;
    cin >>n;
    string t;
    cin >> t;
    int sum = 0;
    for(int i =0 ; i<t.size(); i++){
        if(t[i] == '(') a[i+1] = 1;
        else a[i+1] = -1;
        s[i+1] = s[i] + a[i+1];
    }
    if(s[n] != 0){
        cout<<-1<<endl;
        return 0;
    }
    int x = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] < 0) {
            while(s[i] < 0) i++, ans++;
            ans++;
        }
    }
    cout<<ans<<endl;

}