#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> P;

const int INF = 100000000;

P dp[205][205][205];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s += '.';
    t += '.';
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) for(int k = 0; k <= 202; k++) dp[i][j][k] = P(INF, 0);
    dp[0][0][0] = P(0, 0);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= 200; k++){
                if(s[i] == '(' && t[j] == '(')
                    dp[i + 1][j + 1][k + 1] = min(dp[i + 1][j + 1][k + 1], P(dp[i][j][k].first + 1, 7));
                if(s[i] == '(' && t[j] == ')')
                    dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], P(dp[i][j][k].first + 1, 5));
                if(s[i] == '(' && t[j] == '.')
                    dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], P(dp[i][j][k].first + 1, 5));
                if(s[i] == ')' && t[j] == '(')
                    dp[i][j + 1][k + 1] = min(dp[i][j + 1][k + 1], P(dp[i][j][k].first + 1, 6));
                if(s[i] == ')' && t[j] == ')')
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], P(dp[i][j][k].first + 1, 4));
                if(s[i] == ')' && t[j] == '.')
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], P(dp[i][j][k].first + 1, 4));
                if(s[i] == '.' && t[j] == '(')
                    dp[i][j + 1][k + 1] = min(dp[i][j + 1][k + 1], P(dp[i][j][k].first + 1, 6));
                if(s[i] == '.' && t[j] == ')')
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], P(dp[i][j][k].first + 1, 4));
                if(s[i] == '.' && t[j] == '.')
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], P(dp[i][j][k].first + 1, 4));
            }
            for(int k = 200; k > 0; k--){
                if(s[i] == '(' && t[j] == '(')
                    dp[i][j][k - 1] = min(dp[i][j][k - 1], P(dp[i][j][k].first + 1, 0));
                if(s[i] == '(' && t[j] == ')')
                    dp[i][j + 1][k - 1] = min(dp[i][j + 1][k - 1], P(dp[i][j][k].first + 1, 2));
                if(s[i] == '(' && t[j] == '.')
                    dp[i][j][k - 1] = min(dp[i][j][k - 1], P(dp[i][j][k].first + 1, 0));
                if(s[i] == ')' && t[j] == '(')
                    dp[i + 1][j][k - 1] = min(dp[i + 1][j][k - 1], P(dp[i][j][k].first + 1, 1));
                if(s[i] == ')' && t[j] == ')')
                    dp[i + 1][j + 1][k - 1] = min(dp[i + 1][j + 1][k - 1], P(dp[i][j][k].first + 1, 3));
                if(s[i] == ')' && t[j] == '.')
                    dp[i + 1][j][k - 1] = min(dp[i + 1][j][k - 1], P(dp[i][j][k].first + 1, 1));
                if(s[i] == '.' && t[j] == '(')
                    dp[i][j][k - 1] = min(dp[i][j][k - 1], P(dp[i][j][k].first + 1, 0));
                if(s[i] == '.' && t[j] == ')')
                    dp[i][j + 1][k - 1] = min(dp[i][j + 1][k - 1], P(dp[i][j][k].first + 1, 2));
                if(s[i] == '.' && t[j] == '.')
                    dp[i][j][k - 1] = min(dp[i][j][k - 1], P(dp[i][j][k].first + 1, 0));
            }
        }
    }
    int i = n, j = m, k = 0;
    vector<char> v;
    while(i != 0 || j != 0 || k != 0){
        int b = dp[i][j][k].second;
        if((b >> 0) & 1) i--;
        if((b >> 1) & 1) j--;
        if((b >> 2) & 1){
            k--;
            v.push_back('(');
        }
        else{
            k++;
            v.push_back(')');
        }
    }
    for(auto itr = v.rbegin(); itr != v.rend(); itr++){
        cout << *itr;
    }
    cout << endl;
}