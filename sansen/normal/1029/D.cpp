#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    
    int s[n];
    for(int i = 0; i < n; i++)  cin >> s[i];
    
    ll ten[11];
    ten[0] = 1;
    for(int i = 1; i < 11; i++) ten[i] = ten[i-1]*10%k;

    map<int,int> cnt[11];
    for(int i = 0; i < n; i++){
        int len = to_string(s[i]).length();
        int mod = s[i]%k;
        cnt[len][mod]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < 11; j++){
            int want = (k-ten[j]*s[i]%k)%k;
            if (cnt[j].count(want)) {
               ans += cnt[j][want];
            }
        }
        int len = to_string(s[i]).length();
        int want = (k-ten[len]*s[i]%k)%k;
        ans -= want==(s[i]%k);
    }

    cout << ans << endl;
    return 0;
}