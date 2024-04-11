#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string s;
        cin >> s;
        int n = s.size();
        int a[26] {0};
        for(int i = 0; i < n; i++){
            a[s[i] - 'a']++;
        }
        string ans;
        bool f;
        ans = "";
        f = true;
        for(int i = 0; i < 26; i += 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = ans + t;
        }
        for(int i = 1; i < 26; i += 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = t + ans;
        }
        for(int i = 1; i < n; i++) if(ans[i] - ans[i - 1] == 1 || ans[i] - ans[i - 1] == -1){
            f = false;
            break;
        }
        if(f){
            cout << ans << endl;
            continue;
        }
        ans = "";
        f = true;
        for(int i = 24; i >= 0; i -= 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = ans + t;
        }
        for(int i = 1; i < 26; i += 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = t + ans;
        }
        for(int i = 1; i < n; i++) if(ans[i] - ans[i - 1] == 1 || ans[i] - ans[i - 1] == -1){
            f = false;
            break;
        }
        if(f){
            cout << ans << endl;
            continue;
        }
        ans = "";
        f = true;
        for(int i = 0; i < 26; i += 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = ans + t;
        }
        for(int i = 25; i >= 0; i -= 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = t + ans;
        }
        for(int i = 1; i < n; i++) if(ans[i] - ans[i - 1] == 1 || ans[i] - ans[i - 1] == -1){
            f = false;
            break;
        }
        if(f){
            cout << ans << endl;
            continue;
        }
        ans = "";
        f = true;
        for(int i = 24; i >= 0; i -= 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = ans + t;
        }
        for(int i = 25; i >= 0; i -= 2){
            string t = "";
            for(int j = 0; j < a[i]; j++) t += char('a' + i);
            ans = t + ans;
        }
        for(int i = 1; i < n; i++) if(ans[i] - ans[i - 1] == 1 || ans[i] - ans[i - 1] == -1){
            f = false;
            break;
        }
        if(f){
            cout << ans << endl;
            continue;
        }
        cout << "No answer" << endl;
    }
}