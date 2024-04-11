#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int ind = -1;
    for(int i = 0; i < n; i++)if(s[i] == '*')ind = i;

    bool ans = false;
    if(ind == -1){
        if(s == t)ans = true;
    }
    else{
        int k = m - n;
        if(k >= -1){
            ans = true;
            for(int i = 0; i < ind; i++)if(s[i] != t[i])ans = false;
            for(int i = ind + 1; i < n; i++)if(s[i] != t[i + k])ans = false;
        }
    }

    if(ans)cout << "YES";
    else cout << "NO";
}