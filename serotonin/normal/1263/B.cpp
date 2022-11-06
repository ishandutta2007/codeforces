#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        int n;
        string s[20];
        cin >> n;
        for(int i=0; i<n; i++) cin >> s[i];
        ll ans=0;
        for(int i=0; i<n; i++) {
            bool yes=0;
            for(int j=i+1; j<n; j++) {
                if(s[i]==s[j]) yes=1;
            }
            if(yes) {
                ans++;
                bool done=0;
                for(int k=0; k<4 && !done; k++) {
                    for(int l=0; l<10; l++) {
                        string now = s[i];
                        now[k]=('0'+l);
                        bool ok=1;
                        for(int j=0; j<n; j++) {
                            if(s[j]==now) ok=0;
                        }
                        if(ok) {
                            s[i]=now;
                            done=1;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        for(int i=0; i<n; i++) cout << s[i] << endl;
    }
}