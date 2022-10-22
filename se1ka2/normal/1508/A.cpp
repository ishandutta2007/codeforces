#include <iostream>
using namespace std;

string answer(string &s, string &t, int n, char ma, char mi){
    string res;
    int i = 0, j = 0;
    int c = 0;
    while(i < n * 2 || j < n * 2){
        if((i < n * 2 && s[i] == mi) || (j < n * 2 && t[j] == mi)){
            c++;
            if((i < n * 2 && s[i] == mi)) i++;
            if((j < n * 2 && t[j] == mi)) j++;
        }
        else{
            for(int k = 0; k < c; k++) res += mi;
            res += ma;
            c = 0;
            if(i < n * 2) i++;
            if(j < n * 2) j++;
        }
    }
    for(int k = 0; k < c; k++) res += mi;
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s[3];
        for(int i = 0; i < 3; i++) cin >> s[i];
        int c[3]{0};
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n * 2; j++) c[i] += s[i][j] - '0';
        }
        string ans;
        if(c[0] <= n){
            if(c[1] <= n) ans = answer(s[0], s[1], n, '0', '1');
            else if(c[2] <= n) ans = answer(s[0], s[2], n, '0', '1');
            else ans = answer(s[1], s[2], n, '1', '0');
        }
        else{
            if(c[1] > n) ans = answer(s[0], s[1], n, '1', '0');
            else if(c[2] > n) ans = answer(s[0], s[2], n, '1', '0');
            else ans = answer(s[1], s[2], n, '0', '1');
        }
        cout << ans << endl;
    }
}