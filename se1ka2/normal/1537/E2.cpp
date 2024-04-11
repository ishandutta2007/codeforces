#include <iostream>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t = "";
    int l = -1;
    int j = 0;
    for(int i = 1; i < n; i++){
        if(l == -1){
            if(s[i] > s[0]){
                t = s.substr(0, i);
                break;
            }
            if(s[i] == s[0]){
                l = i;
                j = 0;
            }
        }
        if(l >= 0){
            if(s[i] > s[j]){
                t = s.substr(0, l);
                break;
            }
            if(s[i] < s[j]) l = -1;
            j++;
        }
    }
    if(t == ""){
        if(l == -1) t = s;
        else t = s.substr(0, l);
    }
    string ans;
    while((int)ans.size() < k) ans += t;
    cout << ans.substr(0, k) << endl;
}